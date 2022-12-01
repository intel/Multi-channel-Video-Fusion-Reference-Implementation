# Video-fusion
This reference implementation provides high performance real-time video virtual background replacement and fusion with multiple sources including, camera, videos and png file. Solution can be reference in scenarios: online broadcasting, video conferencing, and media playback
It is fully accelerated with Intel QSV/OpenCL
![image](https://user-images.githubusercontent.com/43125192/196908078-83d0eaa2-ff19-4c08-8859-ecff66ecb7de.png)


## Compile: 
To compile 
1. Download QTAV (https://github.com/wang-bin/QtAV/releases/tag/v1.13.0)
Build QTAV folow guide https://github.com/wang-bin/QtAV/wiki/Build-QtAV
put QtAVWidgets1.dll,  QtAV1.dll under QTAV folder 
copy all QTAV dependencies libray to video-fusion/release folder.
2. Copy FFmpeg bin file to video-fusion/ffmpeg
Install QT and build the project with video_editing.pro.

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


## Environment Setup: 

### Monaserver
To support stream function, a stream server is needed. In our POC, Monaserver is used to setup streaming service.  
Recommend to download below version  
https://sourceforge.net/projects/monaserver/files/MonaServer/MonaServer_Win64.zip/download

Tips about setup Monaserver:  
Please go to the installation directly, and "Run as Adminstrator". Make sure all the server can be started correctly.   
![image](https://user-images.githubusercontent.com/43125192/187343177-869bb413-faa5-4deb-aaba-0fecc6e65f05.png)

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
