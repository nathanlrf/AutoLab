function varargout = exp2_content(varargin)
% EXP2_CONTENT MATLAB code for exp2_content.fig
%      EXP2_CONTENT, by itself, creates a new EXP2_CONTENT or raises the existing
%      singleton*.
%
%      H = EXP2_CONTENT returns the handle to a new EXP2_CONTENT or the handle to
%      the existing singleton*.
%
%      EXP2_CONTENT('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in EXP2_CONTENT.M with the given input arguments.
%
%      EXP2_CONTENT('Property','Value',...) creates a new EXP2_CONTENT or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before exp2_content_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to exp2_content_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help exp2_content

% Last Modified by GUIDE v2.5 28-Apr-2014 17:56:05

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @exp2_content_OpeningFcn, ...
                   'gui_OutputFcn',  @exp2_content_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before exp2_content is made visible.
function exp2_content_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to exp2_content (see VARARGIN)

% Choose default command line output for exp2_content
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes exp2_content wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = exp2_content_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;
