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

if nargin == 0
    varargin = {'all'};
end
for k = 1 : numel(varargin)
    switch varargin{k}
        case 'help'
            fprintf('Make command from MATLAB. It requires having ''make'' installed and added to the PATH of your computer.\nUsage:\n');
            fprintf('- ''make all'' or ''make'': generate code from Simulink, build and upload\n');
            fprintf('- ''make gencode'': generate code only\n')
            fprintf('- ''make build'': build only\n');
            fprintf('- ''make upload'': upload only\n');
            fprintf('- ''make clean'': clean the build and cache directories\n');
            fprintf('- ''make remake'': clean, genenerate code, build and upload\n');
            fprintf('- ''make rebuild'': clean and build only\n');
            fprintf('- ''make doc'': generate the documentation\n');
            fprintf('- ''make cleandoc'': clean the documentation\n');
            fprintf('- ''make help'':print this help\n');
            fprintf('You may also use multiple commands at the same time, e.g. ''make build upload'' to build and upload\n')
            return;
        case 'all'
            gencode();
            fprintf('Buiding code...\n')
            !make build
            fprintf('Uploading code...\n')
            !make upload
            return;
        case 'gencode'
            gencode();
        case 'build'
            fprintf('Building code...\n')
            !make build
        case 'upload'
            fprintf('Uploading code...\n')
            !make upload
        case 'clean'
            fprintf('Cleaning code...\n');
            !make clean
        case 'remake'
            fprintf('Cleaning code...\n');
            !make clean
            gencode();
            fprintf('Buiding code...\n')
            !make build
            fprintf('Uploading code...\n')
            !make upload
        case 'rebuild'
            fprintf('Cleaning code...\n');
            !make clean
            fprintf('Buiding code...\n')
            !make build
        case 'doc'
            !make doc
        case 'cleandoc'
            !make cleandoc
        otherwise
            error(['invalid command ''' varargin{k} '''. Type ''make help'' to print the usage.'])
    end
end
end

