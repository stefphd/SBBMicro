function check_toolbox(input)
%CHECK_TOOLBOX(input) checks for the toolboxes used by the code generation and inform the user 
%for missing toolboxes. 
%Param 'input' is the searching folder(s) or file(s). If missing all *.m and
%*.slx files in the current directory are checked. If a folder or a list of
%folders, all *.m and *.slx contained are checked.
%Created by Stefano Lovato
%Creation data: 5th April 2022
%Last edit: 5th Aprile 2022
%Created with MATLAB R2022a

fprintf('###################################################\n');
fprintf('# Check toolboxes\n');
%fprintf('# Description: check for the toolboxes used by the code generation and inform the user\n');
%fprintf('# for missing toolboxes.\n');
%fprintf('# Param ''input'' is the searching folder(s) or file(s). If missing all *.m and\n');
%fprintf('# *.slx files in the current directory are checked. If a folder or a list of\n');
%fprintf('# folders, all *.m and *.slx contained are checked.\n');
fprintf('# Created by Stefano Lovato\n');
fprintf('# Creation data: 5th April 2022\n');
fprintf('# Last edit: 5th Aprile 2022\n');
fprintf('# Created with MATLAB R2022a\n');
fprintf('###################################################\n');

%% inputs

fprintf('# Searching for files...')

valid_ext = {'.m', '.slx'};

if nargin < 1
    input = pwd;
end
if ~iscell(input)
    input = {input};
end

files = {};
for k = 1 : numel(input)
    if isfolder(input)
        for l = 1 : numel(valid_ext)
            ff = dir([input{k} '/*' valid_ext{l}]);
            for h = 1 : numel(ff)
                if ~strcmp(ff(h).name, 'check_toolbox.m')
                    files = [files; [ff(h).folder '/' ff(h).name]];
                end
            end
        end

    else %is a file
        [~, ~, fExt] = fileparts(input{k});
        if any(strcmp(fExt,valid_ext))
            files = [files; filename];
        end
    end
end

if isempty(files) 
    error('No valid files found.')
end

fprintf('Done.\n')

%% check
toolbox = {};
for k = 1 : numel(files)
    [~, name, ext] = fileparts(files{k});
    fprintf('# Finding toolboxes used by %s...', [name ext]);
    [~, toolbox_file{k}] = dependencies.toolboxDependencyAnalysis(files{k});
    toolbox = [toolbox(:); toolbox_file{k}(:)];
    fprintf('Done.\n');
end
toolbox = unique(toolbox);

%% print
fprintf('# A total of %d toolboxes are being used.\n',numel(toolbox));
fprintf('# List of used toolboxes:\n');
for k = 1 : numel(toolbox)
    fprintf('#\t-%s used by ',toolbox{k});
    for l = 1 : numel(files)
        if any(strcmp(toolbox{k}, toolbox_file{l}))
            [~, name, ext] = fileparts(files{l});
            fprintf('%s ', [name ext]);
        end
    end
    fprintf('.\n');
end

%% Check for toolboxes in MATLAB
fprintf('# Checking for installed toolboxes...');
for k = 1 : numel(toolbox) 
    result_check = ver(toolbox{k});
    if ~isempty(result_check)
        check(k) = true;
    else
        check(k) = false;
    end
end
fprintf('Done.\n');

%% Inform the user for missing toolboxes
if any(~check)
   fprintf('# A total of %d missing toolboxes found.\n', sum(~check));
   fprintf('# List of missing toolboxes:\n')
   for k = 1 : numel(check)
        if ~check(k)
            fprintf('#\t-%s used by ',toolbox{k});
            for l = 1 : numel(files)
                if any(strcmp(toolbox{k}, toolbox_file{l}))
                    [~, name, ext] = fileparts(files{l});
                    fprintf('%s ', [name ext]);
                end
            end
        end
   end
else
    fprintf('# No missing toolboxes found.\n')
end

%% EOF
fprintf('###################################################\n');