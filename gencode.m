function gencode(modelname,destdir)
%GENCODE(modelname,dest_dir) This function generates the C++ code for the Simulink model 'model' specified by the user (with no extension).
%If no input is specified, the function uses the first *.slx file found in
%the current directory, with the destination folder 'lib'.
%The generated code is placed in ./'dest_dir'/'modelname'/src

%Created by SL

%% gen code
if (nargin<1)
    modelname = '~';
end
if modelname == '~' %use default .slx file found
    %find first .slx file found
    files = dir('*.slx');
    if isempty(files)
        error('No *.slx files found in the current directory');
    end
    modelname = files(1).name(1:end-4);
end
if nargin<2 %use default .slx file found
    destdir = 'lib';
    CodeGenFolder = ['lib/' modelname];
else
    CodeGenFolder = [destdir '/' modelname];
end


Simulink.fileGenControl('set', ...
    'CacheFolder', '.cache', ...
    'CodeGenFolder', CodeGenFolder, ...
    'CodeGenFolderStructure', ...
    Simulink.filegen.CodeGenFolderStructure.ModelSpecific, ...
    'createDir', true); %setup folders

load_system([modelname '.slx']); %load simulink model
set_param(modelname,'GenCodeOnly','on'); %set generate code only to on (do not generate .exe, useless)
slbuild(modelname) %build

Simulink.fileGenControl('reset') %reset setup

%% make include file for quick include in source code
dir_main = [CodeGenFolder '/' modelname '_ert_rtw' '/'];
dir_shared = [CodeGenFolder '/slprj/ert/_sharedutils/'];
dir_codegen = [CodeGenFolder '/src/'];
codegen_file = [CodeGenFolder '/genlibs.h'];

list_h_main = dir([dir_main '*.h']);
list_c_main = dir([dir_main '*.c']);
list_cpp_main = dir([dir_main '*.cpp']);
list_h_shared = dir([dir_shared '*.h']);
list_c_shared = dir([dir_shared '*.c']);
list_cpp_shared = dir([dir_shared '*.cpp']);
fprintf('### Performing post-generation operations...\n');
fileID = fopen(codegen_file,'w');

if ~exist(dir_codegen,'dir') 
    mkdir(dir_codegen);
end

for k = 1 : numel(list_h_main) 
    if ~contains(list_h_main(k).name,'main') %exclude main files
        fprintf(fileID,'#include "src/%s"\n', list_h_main(k).name);
        copyfile([dir_main list_h_main(k).name], [dir_codegen list_h_main(k).name]);
    end
end
for k = 1 : numel(list_c_main)
    if ~contains(list_c_main(k).name,'main') %exclude main files
        copyfile([dir_main list_c_main(k).name], [dir_codegen list_c_main(k).name]);
    end
end
for k = 1 : numel(list_cpp_main) 
    if ~contains(list_cpp_main(k).name,'main') %exclude main files
        copyfile([dir_main list_cpp_main(k).name], [dir_codegen list_cpp_main(k).name]);
    end
end
for k = 1 : numel(list_h_shared) 
    if ~contains(list_h_shared(k).name,'main') %exclude main files;
        fprintf(fileID,'#include "src/%s"\n', list_h_shared(k).name);
        copyfile([dir_shared list_h_shared(k).name], [dir_codegen list_h_shared(k).name]);
    end
end
for k = 1 : numel(list_c_shared)
    if ~contains(list_c_shared(k).name,'main') %exclude main files
        copyfile([dir_shared list_c_shared(k).name], [dir_codegen list_c_shared(k).name]);
    end
end
for k = 1 : numel(list_cpp_shared) 
    if ~contains(list_cpp_shared(k).name,'main') %exclude main files
        copyfile([dir_shared list_cpp_shared(k).name], [dir_codegen list_cpp_shared(k).name]);
    end
end
fclose(fileID);

%% end
fprintf('Code generation finished\n');

end
