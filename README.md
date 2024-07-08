# DISCONTINUATION OF PROJECT  
This project will no longer be maintained by Intel.  
Intel has ceased development and contributions including, but not limited to, maintenance, bug fixes, new releases, or updates, to this project.  
Intel no longer accepts patches to this project.  
If you have an ongoing need to use this project, are interested in independently developing it, or would like to maintain patches for the open source software community, please create your own fork of this project.  

# Video-fusion
This reference implementation provides high performance real-time video virtual background replacement and fusion with multiple sources including, camera, videos and png file. Solution can be reference in scenarios: online broadcasting, video conferencing, and media playback
It is fully accelerated with Intel QSV/OpenCL
![image](https://user-images.githubusercontent.com/43125192/196908078-83d0eaa2-ff19-4c08-8859-ecff66ecb7de.png)

## Compile: 
To compile 
1.	QTAV (https://github.com/wang-bin/QtAV/releases/tag/v1.13.0) 
Download and build QTAV. Refer to the guide https://github.com/wang-bin/QtAV/wiki/Build-QtAV put QtAVWidgets1.dll, QtAV1.dll under QTAV folder and copy all the QTAV dependencies library to video-fusion/release folder.
2.	Follow the guide below to compile the ffmpeg and apply patches
FFmpeg ( https://github.com/intel-media-ci/cartwheel-ffmpeg)

$ git clone https://github.com/intel-media-ci/cartwheel-ffmpeg --recursive
$ git submodule update --init --recursive
$ cd ffmpeg
# It is recommended to create a branch before applying the patches
$ git checkout -b <my new branch>
$ git am ../patches/*.patch

Then apply additional path for this reference implementation

$ git am <path to video fusion>/ffmpeg/*.patch

https://github.com/intel-media-ci/cartwheel-ffmpeg/archive/refs/tags/2022q2.tar.gz

3.	Enable OneVPL and OpenCL, compile FFmpeg with the command below:

PKG_CONFIG_PATH="/mingw64/lib/pkgconfig:/C/msys64/home/ojuan/_vplinstall/lib/pkgconfig:$PKG_CONFIG_PATH" ../configure --enable-shared --disable-static --enable-dxva2 --enable-d3d11va --enable-libx264 --enable-gpl --enable-libvpl --enable-opencl --enable-sdl --enable-logging --disable-doc --arch=x86_64 --target-os=mingw64 --disable-mmx --prefix=../build/
4.	Refer to document 728030_Compiling_QSV_on_Windows_Linux_Platform_rev1.0.pdf for more details.
5.	Copy FFmpeg bin file to video-fusion/ffmpeg 
FFMPEG Enhancements:
•	FFMPEG library supports green screen color key on intel integrated GPU by optimizing OpenCL overlay_opencl and combine color key and overlay into one function
•	FFMPEG library supports hwmap between qsv and d3d11, reduces memory move/copy, d3d11 NV12 format support
6.	Install QT and build the project with video_editing.pro.

## Features: 
### Major Features:
* Enables end to end media processing pipeline based on Intel QSV OneVPL acceleration
* APP supports 2 - 4 inputs with 1-2 channels green screen video
* APP supports video streaming withs support of MonaServer, or save output file as mp4 
* APP supports video play with QTAV player
* APP supports processing AI based segmentation input with Intel virtual camera technology (for this advanced feature, please request author for details)

### FFMPEG Enhancements:
* FFMPEG library supports green screen color key on intel integrated GPU by optimizing OpenCL overlay_opencl and combine color key and overlay into one function
* FFMPEG library supports hwmap between qsv and d3d11, reduces memory move/copy, d3d11 NV12 format support

## UI Interface: 

![image](https://user-images.githubusercontent.com/43125192/187363065-b05402a0-027f-4b3b-84fd-dcde210faf83.png)


## Setup and Test: 

### Monaserver
1.	To support the stream function, a stream server is needed. In our reference implementation, Monaserver is used to setup streaming service.
2.	It is recommended to download the version below
https://sourceforge.net/projects/monaserver/files/MonaServer/MonaServer_Win64.zip/download
3.	Steps to setup MonaServer:
a.	Go to the installation directly, and "Run as Administrator". Make sure all the servers can be started correctly.
![image](https://user-images.githubusercontent.com/43125192/187343177-869bb413-faa5-4deb-aaba-0fecc6e65f05.png)

## Application Scenarios
### 	Video Mode
1.	1 foreground green screen video mp4 + 1 background mp4 video
APP accelerates foreground green screen video with OpenCL color key, and overlay with background mp4 
2.	1 foreground video + 1 background green screen video + 1 Roll Ad Video + 1 PNG ad APP accelerate foreground green screen video and roll- ad green screen video with OpenCL color key, and overlay with background mp4, finally overlay PNG file to combined videos
The output file can be
a.	Save as files (mp4)
b.	Or streaming out with (streaming) 
Before streaming, set up the MonaServer. In this demo, we used the local machine as streaming server for in and out stream. rtmp://127.0.0.1:1935/live address is used for playing the streaming video. 
Click Stream button and Open rtmp://127.0.0.1:1935/live directly to view the streaming stream

###	Camera Mode
Replacing the second stream with Intel Virtual Camera solution, which outputs a live camera stream with green screen background. This camera stream will be color keyed with opencl and overlay as in video mode
The same pipeline as video mode will be used for both
1.	1 foreground Camera input + 1 background mp4 video
APP accelerates foreground green screen video with OpenCL color key, and overlay with background mp4
1 foreground Camera input + 1 background green screen video + 1 Roll Ad Video + 1 PNG ad
2.	APP accelerate foreground green screen video and roll- ad green screen video with OpenCL color key, and overlay with background mp4, finally overlay PNG file to combined videos
The output file can be 
a.	Save as files (mp4)
b.	Or streaming out with (streaming) 

## Dependencies:

### FFMPEG
FFmpeg is an open source project licensed under LGPL and GPL. See https://www.ffmpeg.org/legal.html. You are solely responsible for determining if your use of FFmpeg requires any additional licenses. Intel is not responsible for obtaining any such licenses, nor liable for any licensing fees due, in connection with your use of FFmpeg.

https://github.com/intel-media-ci/cartwheel-ffmpeg  
Intel developer staging area for upstream patch contributions to FFmpeg is used.  
Our build enables OneVPL, OpenCL and few additional patches, for compiling guide, please refer to 728030_Compiling_QSV_on_Windows_Linux_Platform_rev1.0.pdf

### Intel Virtual Camera hotkey
Intel virtual camera technology hotkey.
After enabling the virtual camera AI background replacement with a green screen background, APP can directly output live streams with any type of camera input.

### QTAV:
https://github.com/wang-bin/QtAV  
A cross-platform multimedia framework based on Qt and FFmpeg  
Video Fusion APP integrates a media player using QtAV. 

Project in maintenance
