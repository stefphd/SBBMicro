function gencode(model)
%Created by SL

%% gen code
if nargin==0 %use default .slx file found
    model = 'controlModel.slx';
end

CodeGenFolder = 'lib/controlModel';

Simulink.fileGenControl('set', ...
    'CacheFolder', '.cache', ...
    'CodeGenFolder', CodeGenFolder, ...
    'CodeGenFolderStructure', ...
    Simulink.filegen.CodeGenFolderStructure.ModelSpecific, ...
    'createDir', true); %setup folders

load_system(model); %load simulink model
set_param(model(1:end-4),'GenCodeOnly','on'); %set generate code only to on (do not generate .exe, useless)
slbuild(model(1:end-4)) %build

Simulink.fileGenControl('reset') %reset setup

%% make include file for quick include in source code
dir_main = [CodeGenFolder filesep model(1:end-4) '_ert_rtw' filesep];
dir_shared = [CodeGenFolder filesep 'slprj' filesep 'ert' filesep '_sharedutils' filesep ];
dir_codegen = [CodeGenFolder '/src/'];
codegen_file = 'include/genlibs.h';

list_h_main = dir([dir_main '*.h']);
list_c_main = dir([dir_main '*.c']);
list_cpp_main = dir([dir_main '*.cpp']);
list_h_shared = dir([dir_shared '*.h']);
list_c_shared = dir([dir_shared '*.c']);
list_cpp_shared = dir([dir_shared '*.cpp']);
fprintf('### Generating include library file genlibs.h\n');
fileID = fopen(codegen_file,'w');
fprintf(fileID,'// include generated code file\n');
fprintf(fileID,['// just use #include <' codegen_file '> in your main file\n']);
fprintf(fileID,'// file generated on %s by %s\n', datestr(datetime(now,'ConvertFrom','datenum')), getenv('username'));

if ~exist(dir_codegen,'dir') 
    mkdir(dir_codegen);
end

for k = 1 : numel(list_h_main) 
    if ~contains(list_h_main(k).name,'main') %exclude main files
        fprintf(fileID,'#include <%s>\n', list_h_main(k).name);
        copyfile([dir_main list_h_main(k).name], [dir_codegen list_h_main(k).name]);
    end
end
for k = 1 : numel(list_c_main)
    if ~contains(list_c_main(k).name,'main') %exclude main files
        %fprintf(fileID,'#include "%s"\n', list_c_main(k).name);
        copyfile([dir_main list_c_main(k).name], [dir_codegen list_c_main(k).name]);
    end
end
for k = 1 : numel(list_cpp_main) 
    if ~contains(list_cpp_main(k).name,'main') %exclude main files
        %fprintf(fileID,'#include "%s"\n', list_cpp_main(k).name);
        copyfile([dir_main list_cpp_main(k).name], [dir_codegen list_cpp_main(k).name]);
    end
end
for k = 1 : numel(list_h_shared) 
    if ~contains(list_h_shared(k).name,'main') %exclude main files;
        fprintf(fileID,'#include <%s>\n', list_h_shared(k).name);
        copyfile([dir_shared list_h_shared(k).name], [dir_codegen list_h_shared(k).name]);
    end
end
for k = 1 : numel(list_c_shared)
    if ~contains(list_c_shared(k).name,'main') %exclude main files
        %fprintf(fileID,'#include "%s"\n', list_c_shared(k).name);
        copyfile([dir_shared list_c_shared(k).name], [dir_codegen list_c_shared(k).name]);
    end
end
for k = 1 : numel(list_cpp_shared) 
    if ~contains(list_cpp_shared(k).name,'main') %exclude main files
        %fprintf(fileID,'#include "%s"\n', list_cpp_shared(k).name);
        copyfile([dir_shared list_cpp_shared(k).name], [dir_codegen list_cpp_shared(k).name]);
    end
end
fclose(fileID);

%% end
fprintf('Code generation finished\n');

end
