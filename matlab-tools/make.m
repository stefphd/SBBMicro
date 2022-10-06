function make(varargin)
%MAKE This is a wrapper around the make command being used from the
%terminal. This implements also make gencode for code generation and make
%all for gencode, build, and upload. Default make is 'make all'.
%It requires having 'make' installed and added to the PATH of your
%computer.
%Use 'make help' to print the help.
%Created by Stefano Lovato
%Creation date: 29th September 2022
%Create with MATLAB R2022a

global NAME BOARD BOARD_OPTIONS SRC BUILD_PATH CACHE_PATH ARDUINO_FOLDER BUILD_TOOLS ...
       BUILDER POSTCOMPILER REBOOT HARDWARE FQBN LIBRARIES TOOLS FLAGS DOCS_PATH

%---------------------------------------------------------------------------------
% USER SETTINGS
%---------------------------------------------------------------------------------

%Name of the main file
NAME                = 'main.cpp';

%Board
BOARD               = 'teensy41';
BOARD_OPTIONS       = 'speed=600,usb=mtpserial,opt=o3std,keys=en-us';

%Directories
SRC                 = './src';
BUILD_PATH          = './.build';
CACHE_PATH          = './.cache';
DOCS_PATH           = './docs';
if ispc
    ARDUINO_FOLDER  = 'C:/Program Files (x86)/Arduino';
    BUILD_TOOLS     = './tools/tools-windows';
elseif isunix
    ARDUINO_FOLDER  = '/usr/share/arduino';
    BUILD_TOOLS     = './tools/tools-linux';
else
    error('OS not supported')
end

%---------------------------------------------------------------------------------
% USUALLY EDITING BELOW THIS LINE NOT NECESSARY
%---------------------------------------------------------------------------------

BUILDER			    = [ARDUINO_FOLDER   '/arduino-builder'];
POSTCOMPILER	    = [BUILD_TOOLS      '/teensy_post_compile'];
REBOOT			    = [BUILD_TOOLS      '/teensy_reboot'];

%Builder options (be careful to change this)
HARDWARE		    = '-hardware ./tools';
FQBN			    = ['-fqbn=teensy:avr:' BOARD ':' BOARD_OPTIONS];
LIBRARIES		    = '-libraries ./ -libraries ./include/ -libraries ./lib/';
TOOLS			    = ['-tools "' BUILD_TOOLS '" -tools "' ARDUINO_FOLDER '/tools-builder"'];
FLAGS			    = ''; %'-verbose'

%---------------------------------------------------------------------------------
% DO NOT EDIT BELOW THIS LINE
%---------------------------------------------------------------------------------

if nargin == 0
    varargin = {'all'};
end
k = 1;
while k <= numel(varargin)
    switch varargin{k}
        case 'help'
            help();
            return;
        case 'all'
            all();
        case 'gencode'
            [name, dir, k] = gencode_parse(k, varargin);
            gencode(name, dir);
        case 'build'
            build();
        case 'upload'
            upload();
        case 'clean'
            clean();
        case 'remake'
            remake();
        case 'rebuild'
            rebuild();
        case 'doc'
            doc();
            return;
        case 'cleandoc'
            cleandoc();
            return;
        case 'cleanall'
            cleanall();
            return;
        otherwise
            error(['invalid command ''' varargin{k} '''. Type ''make help'' to print the usage.'])
    end
    k = k + 1;
end
end

function help()
        fprintf('Make command from MATLAB. It requires having ''make'' installed and added to the PATH of your computer.\nUsage:\n');
        fprintf('- ''make all'' or ''make'': generate code from Simulink, build and upload\n');
        fprintf('- ''make gencode [-n NAME -d DIRECTORY] [--name NAME --dir DIRECTORY]'': generate code only\n')
        fprintf('- ''make build'': build only\n');
        fprintf('- ''make upload'': upload only\n');
        fprintf('- ''make clean'': clean the build and cache directories\n');
        fprintf('- ''make remake'': clean, genenerate code, build and upload\n');
        fprintf('- ''make rebuild'': clean and build only\n');
        fprintf('- ''make doc'': generate the documentation\n');
        fprintf('- ''make cleandoc'': clean the documentation\n');
        fprintf('- ''make cleanall'': clean build, cache and documentation\n');
        fprintf('- ''make help'': print this help\n');
        fprintf('You may also use multiple commands at the same time, e.g. ''make build upload'' to build and upload\n')
end

%multiple-task functions
function all()
    gencode();
    build();
    upload();
end

function remake()
    clean();
    all();
end

function rebuild()
    clean();
    build();
end

function cleanall()
    clean();
    cleandoc();
end

%single-task functions
function directories() 
    global BUILD_PATH CACHE_PATH
    fprintf('Making directories...\n')
    [~, ~, ~] = mkdir(BUILD_PATH);
    [~, ~, ~] = mkdir(CACHE_PATH);
end

function clean()
    global BUILD_PATH CACHE_PATH
    [~, ~, ~] = rmdir(BUILD_PATH, 's');
    [~, ~, ~] = rmdir(CACHE_PATH, 's');
end

function build()
    global BUILDER FLAGS BUILD_PATH CACHE_PATH HARDWARE TOOLS LIBRARIES FQBN SRC NAME
    directories();
    fprintf('Buiding code...\n')
    cmd = ['"' BUILDER '"' ' -compile ' FLAGS ' -build-path ' BUILD_PATH ' -build-cache ' CACHE_PATH ...
           ' ' HARDWARE ' ' TOOLS ' ' LIBRARIES ' ' FQBN ' ' SRC '/' NAME];
    disp(cmd);
    exit = system(cmd);
    if exit ~= 0
        error('Build failed');
    end
end

function upload()
    global POSTCOMPILER NAME BUILD_PATH BUILD_TOOLS BOARD REBOOT
    fprintf('Uploading code...\n')
    cmd = ['"' pwd POSTCOMPILER '" -file=' NAME ' -path=' BUILD_PATH ' -tools=' BUILD_TOOLS ' -board teensy:avr:' BOARD];
    disp(cmd);
    exit = system(cmd);
    if exit ~= 0
        error('Upload failed');
    end
    cmd = ['"' pwd REBOOT '"'];
    disp(cmd);
    exit = system(cmd);
    if exit ~= 0
        error('Upload failed');
    end    
end

function doc()
    cleandoc();
    exit = system('doxygen');
    if exit ~= 0
        error('Documentation generation failed');
    end    
end

function cleandoc()
    global DOCS_PATH
    [~, ~, ~] = rmdir([DOCS_PATH '/html'], 's');
end

%parse arguments
function [name, dir, k] = gencode_parse(k, args)
    name = '~';
    dir = '~';
    for l = 1 : 2
        if k+1 <= numel(args)
            if contains(args{k+1}, '-')
                if ~(strcmp(args{k+1}, '-n') || strcmp(args{k+1}, '--name') || strcmp(args{k+1}, '-d') || strcmp(args{k+1}, '--dir'))
                    error(['Invalid argument ''' args{k+1} ''' using gencode. Type ''make help'' to print the usage.'])                        
                end
            end
            if strcmp(args{k+1}, '-n') || strcmp(args{k+1}, '--name')
                if ~(k+2 <= numel(args))
                    error('Argument required after -n/--name or -d/--dir');
                end
                name = args{k+2};
                k = k + 2;
                continue;
            end
            if strcmp(args{k+1}, '-d') || strcmp(args{k+1}, '--dir')
                if ~(k+2 <= numel(args))
                    error('Argument required after -n/--name or -d/--dir');
                end
                dir = args{k+2};
                k = k + 2;
                continue;
            end  
        end
    end
end