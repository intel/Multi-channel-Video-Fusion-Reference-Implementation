/******************************************************************************\
 * Copyright © 2022 Intel Corporation

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

\**********************************************************************************/

#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QProcess>
#include <QScrollBar>
#include "qstandardpaths.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    //Start video processing process
    mVideoProcess = new QProcess(this);
    /*start process*/
    connect(mVideoProcess, SIGNAL(started()), this, SLOT(VideoprocessStarted()));
    /*output message to window*/
    connect(mVideoProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(VideoprocessOutputMsg()));
    /*Update Executing status*/
    connect(mVideoProcess, SIGNAL(finished(int)), this, SLOT(Videoprocessended()));
    streamison = false;
    CameraisSelected = false; 
    ui->setupUi(this);

    //Input type: time in seconds, to save or upstream camera stream
    QIntValidator* test_validator = new QIntValidator(-1, 9999, this);
    ui->TimeinSecond->setValidator(test_validator);

    ui->listWidget->setViewMode(QListWidget::IconMode);
    ui->listWidget->setIconSize(QSize(200,180));
    ui->listWidget->setResizeMode(QListWidget::Adjust);

    QListWidgetItem *titleitem = new QListWidgetItem;
    titleitem->setSizeHint(QSize(200, 30));
    titleitem->setText(QString("预览窗口"));
    ui->listWidget->addItem(titleitem);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter paint(this);
    QStyleOption option;
    option.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &option, &paint, this);
    QWidget::paintEvent(e);
}

void Dialog::VideoprocessStarted()
{
    qDebug() << "VideoProcessStarted！";
}

void Dialog::VideoprocessOutputMsg()
{

    qDebug() << "VideoprocessOutputMsg";
}

void Dialog::Videoprocessended()
{
    QString filename = ui->toLineEdit->text();
    qDebug() << "Videoprocessended";

    if((QFile::exists(filename) && (streamison == false)) || (streamison == true))
    {
        ui->StatusLabel->setText("执行状态：成功");
    }
    else
    {
        ui->StatusLabel->setText("执行状态：失败");
    }
    streamison = false;
    ui->streamButton->setEnabled(true);
    ui->startButton->setEnabled(true);
}

QString Dialog::thumbnail_generate(QString filename, int i)
{
    QString program = "ffmpeg/ffmpeg.exe";
    QStringList arguments;
    QString path;

    QString outputfilename = "thumbnail" + QString::number(i) + ".JPG";

    arguments << "-i" << filename <<"-s" << "200x150" <<"-frames:v" << "1" << "-y" << outputfilename;
    path = QDir::currentPath() + "/" + outputfilename;

    mVideoProcess->setProcessChannelMode(QProcess::MergedChannels);
    mVideoProcess->execute(program,arguments);
    mVideoProcess->waitForFinished();
    return path;
}

void Dialog::on_fileOpenButton_clicked()
{
    QString path;
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    "C:/",
                                                    tr("video (*.mp4 *.mov *.avi)"));
    if(!filename.isEmpty()){
        ui->fromLineEdit->setText(filename);
        /**Generate one thumbnail figure and display***/
        path = thumbnail_generate(filename, 0);
        /**Display the thumbnail in list widget**/
        QListWidgetItem *item = new QListWidgetItem(QIcon(path),QString("前景视频"));

        //item->setSizeHint(QSize(180,180));
        ui->listWidget->takeItem(1);
        //ui->listWidget->addItem(item);
        ui->listWidget->insertItem(1, item);
    }

    ui->radioButton->setChecked(false);  //reset radio button
    ui->radioButton->setText("Camera");
    ui->radioButton->setCheckable(false);
    ui->radioButton->setCheckable(true);
}

void Dialog::on_fileOpenButton_1_clicked()
{
    QString path;
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    "C:/",
                                                    tr("video (*.mp4 *.mov *.avi)"));
    if(!filename.isEmpty()){
        ui->fromLineEdit_1->setText(filename);
        path = thumbnail_generate(filename, 1);
        /**Display the thumbnail in list widget**/
        QListWidgetItem *item = new QListWidgetItem(QIcon(path),QString("特写视频"));
        //item->setSizeHint(QSize(180,180));
        //ui->listWidget->addItem(item);

        ui->listWidget->takeItem(2);
        //ui->listWidget->addItem(item);
        ui->listWidget->insertItem(2, item);
    }
}


void Dialog::on_fileOpenButton_2_clicked()
{
    QString path;
    QString filename = QFileDialog::getOpenFileName(this,
                                                     tr("Open File"),
                                                     "C:/",
                                                     tr("video (*.png)"));
     if(!filename.isEmpty()){
         ui->fromLineEdit_2->setText(filename);
         /**Display the thumbnail in list widget**/
         path = thumbnail_generate(filename, 2);
         QListWidgetItem *item = new QListWidgetItem(QIcon(path),QString("贴片图片"));
         
         ui->listWidget->takeItem(3);
         ui->listWidget->insertItem(3, item);
     }
}

void Dialog::on_fileOpenButton_3_clicked()
{
    QString path;
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    "C:/",
                                                    tr("video (*.mp4 *.mov *.avi)"));
    if(!filename.isEmpty()){
        ui->fromLineEdit_3->setText(filename);
        /**Generate one thumtail figure and display***/
        path = thumbnail_generate(filename, 3);
        QListWidgetItem *item = new QListWidgetItem(QIcon(path),QString("背景视频"));

        ui->listWidget->takeItem(4);
        ui->listWidget->insertItem(4, item);
    }
}


void Dialog::on_startButton_clicked()
{
    //QString program = "C:/work/ffmpeg_src/cartwheel-ffmpeg/ffmpeg/build/bin/ffmpeg.exe";
    qDebug() << "start button is clicked";
    /**to get absolute path**/
    QString program = QDir::currentPath() + "/ffmpeg/ffmpeg.exe";

    QStringList arguments;
    QString source = ui->fromLineEdit->text();
    QString source1 = ui->fromLineEdit_1->text();
    QString source2 = ui->fromLineEdit_2->text();
    QString source3 = ui->fromLineEdit_3->text();
    ui->streamButton->setEnabled(false);
    streamison = false;

    ui->StatusLabel->setText("执行状态：");

    if (ui->radioButton->isChecked())
    {
        qDebug()<<"btn is checked";
    }
    else
        qDebug()<<"btn is not checked";

    if((source.isEmpty() && (!ui->radioButton->isChecked()))|| source3.isEmpty())
    {
        qDebug() << "At least 2 input2, background and foreground video";
        QMessageBox::information(this, tr("ffmpeg"), tr("请至少选择背景和前景输入"));
        ui->streamButton->setEnabled(true);
        return;
    }

    QString saveasFilename = ui->toLineEdit->text();
    if(saveasFilename.isEmpty())
    {
        QMessageBox::information(this, tr("ffmpeg"), tr("请输出文件名"));
        ui->streamButton->setEnabled(true);
        return;
    }



    qDebug() << "检查输出文件 " << saveasFilename;
    qDebug() << "QFile::exists(saveasFilename) = " << QFile::exists(saveasFilename);
    if(QFile::exists(saveasFilename))
    {
            if(QMessageBox::question(this, tr("ffmpeg"), tr("文件已经存在当前目录，重写当前文件？"),
                                     QMessageBox::Yes|QMessageBox::No, QMessageBox::No) == QMessageBox::No)
            {
                ui->streamButton->setEnabled(true);
                return;
            }
            QFile::remove(saveasFilename);
            while(QFile::exists(saveasFilename))
            {
                qDebug() << "文件仍然存在";
            }
    }

    QStringList initArguments,initDebugArguments, AccelArguments, CameraArguments;
    initDebugArguments << "-v" << "verbose"  << "-init_hw_device" << "qsv=qs:child_device_type=d3d11va";
    initArguments << "-init_hw_device" << "qsv=qs:child_device_type=d3d11va";
    AccelArguments << "-hwaccel" << "qsv" << "-hwaccel_device" << "qs" << "-c:v" << "h264_qsv";
    CameraArguments << "-rtbufsize" << "1024M" << "-f" << "dshow" << "-i" << Camera_device;
    //QString filter_2ch_4k = "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[main][overlay]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001,format=opencl,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv";
    //QString filter_4ch_4k = "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[2:v]hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv[pngoverlay];[3:v]vpp_qsv=w=1280:h=736,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay2];[main][overlay]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001[compo1];[compo1][overlay2]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv[compo3];[compo3][pngoverlay]overlay_qsv=x=2560:y=640";
    /**Configuration for sports scenarios**/
    //QString filter_2ch_1080p = "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[main][overlay]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001,format=opencl,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv";
    //QString filter_4ch_1080p = "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[2:v]hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv[pngoverlay];[3:v]vpp_qsv=w=640:h=352,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay2];[main][overlay]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001[compo1];[compo1][overlay2]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv[compo3];[compo3][pngoverlay]overlay_qsv=x=1400:y=320:w=480:h=480";
    /*****Configuraiton for other scenarios*****/
    QString filter_2ch_1080p = "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[main][overlay]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03,format=opencl,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv";
    QString filter_4ch_1080p = "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[2:v]hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv[pngoverlay];[3:v]vpp_qsv=w=640:h=352,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay2];[main][overlay]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.030[compo1];[compo1][overlay2]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv[compo3];[compo3][pngoverlay]overlay_qsv=x=1400:y=320:w=480:h=480";

    QString filter_2ch_camera ="[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]fps=30,hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv,vpp_qsv=w=1920:h=1080:format=nv12,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[main][overlay]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03,format=opencl,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv,setpts=N/FRAME_RATE/TB";
    QString filter_4ch_camera ="[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]fps=30,hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv,vpp_qsv=w=1920:h=1080:format=nv12,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[2:v]hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv[pngoverlay];[3:v]vpp_qsv=w=640:h=352,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay2];[main][overlay]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03[compo1];[compo1][overlay2]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv[compo3];[compo3][pngoverlay]overlay_qsv=x=1400:y=320:w=480:h=480,setpts=N/FRAME_RATE/TB";
    /* arguments supports 2 format
 * 1. background (color key) + forground
 * 2. background (color key) + forground + Roll Ad + close up Ad (colorkey)*/
 /**cmd:ffmpeg.exe -v verbose -init_hw_device qsv=qs:child_device_type=d3d11va -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -i ../../../../linux_video/output_4k_bg.mp4 -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -i ../../../../linux_video/output_4k_green.mp4 -filter_complex "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[main][overlay]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001,format=opencl,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv" -c:v h264_qsv 4k_output_2ch.mp4**/
if (CameraisSelected)
{
    // in camera mode, 2 source are supported only
    int SaveFrames;
    int defaultime = 10;
    if (ui->TimeinSecond->text().isEmpty())  //record 10 second by default, otherwise using the input timeinseconds
        SaveFrames = defaultime * 30;
        else
        SaveFrames = ui->TimeinSecond->text().toInt() * 30;
    /* Mode 1. background  + camer mode forground*/
    if(!source3.isEmpty() && ui->radioButton->isChecked() && source1.isEmpty() && source2.isEmpty())
    {
        arguments << initArguments
                  << AccelArguments
                  <<"-stream_loop"     /**Loop background infinitely*/
                  << "-1"
                  << "-i"
                  << source3
                  << CameraArguments
                  << "-filter_complex"
                  << filter_2ch_camera
                  << "-c:v"
                  << "h264_qsv"
                  << "-vol"
                  << "50"
                  << "-b:v"
                  << "6M"
                  << "-vframes"
                  << QString::number(SaveFrames)
                  << "-y"
                  << saveasFilename;
    }

    /* Mode 2. background  + camer mode forground  + Roll Ad + close up Ad (colorkey)*/
    /**ffmpeg.exe -init_hw_device qsv=qs:child_device_type=d3d11va -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -stream_loop 2 -i C:/ffmpeg_src/linux_video/backgroud_1080.mp4 -rtbufsize 1024M -f dshow -i "video=Intel Virtual Camera" -i C:/ffmpeg_src/linux_video/intel.png -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -stream_loop 2 -i C:/Users/ouyang/Videos/2_hamburger/ad_burger.mp4 -filter_complex "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]fps=30,hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv,vpp_qsv=w=1920:h=1080:format=nv12,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[2:v]hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv[pngoverlay];[3:v]vpp_qsv=w=640:h=352,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay2];[main][overlay]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03[compo1];[compo1][overlay2]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv[compo3];[compo3][pngoverlay]overlay_qsv=x=1400:y=320:w=480:h=480",setpts=N/FRAME_RATE/TB -c:v h264_qsv -b:v 6M -vframes 1000 -y 4ch_camera_burger_lp3.mp4**/

    if(!source3.isEmpty() && !ui->radioButton->isChecked() && !source1.isEmpty() && !source2.isEmpty())
    {
        //to do: add 4 channel mode
        arguments << initArguments
                  << AccelArguments
                  <<"-stream_loop"
                  << "-1"
                  << "-i"
                  << source3
                  << CameraArguments
                  << "-i"
                  << source2
                  << AccelArguments
                  <<"-stream_loop"
                  << "-1"
                  << "-i"
                  << source1
                  << "-filter_complex"
                  << filter_4ch_camera
                  << "-c:v"
                  << "h264_qsv"
                  << "-vol"
                  << "50"
                  << "-b:v"
                  << "6M"
                  << "-vframes"
                  << QString::number(SaveFrames)
                  << "-y"
                  << saveasFilename;

    }
}
else
{
    /****mode 1. background  + video forground (color key)*****/
    if(!source3.isEmpty() && !ui->radioButton->isChecked() && source1.isEmpty() && source2.isEmpty())
    {
        arguments << initArguments
                  << AccelArguments
                  << "-i"
                  << source3
                  << AccelArguments
                  << "-i"
                  << source
                  << "-filter_complex"
                  << filter_2ch_1080p
                  << "-c:v"
                  << "h264_qsv"
                  << "-vol"
                  << "50"
                  << saveasFilename;
    }

    /**Case 2 Example command
    **./ffmpeg.exe -v verbose -init_hw_device qsv=qs:child_device_type=d3d11va -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -i ../../../../linux_video/output_4k_bg.mp4 -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -i ../../../../linux_video/output_4k_green.mp4 -i ../../../../linux_video/intel.png -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -i ../../../../linux_video/output_4k_green.mp4 -filter_complex "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[2:v]hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv[pngoverlay];[3:v]vpp_qsv=w=1280:h=736,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay2];[main][overlay]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001[compo1];[compo1][overlay2]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv[compo3];[compo3][pngoverlay]overlay_qsv=x=2560:y=640" -c:v h264_qsv 4k_4ch_output.mp4
    **/

    if(!source.isEmpty() && !source3.isEmpty() && !source1.isEmpty() && !source2.isEmpty())
    {
        arguments << initArguments
                  << AccelArguments
                  << "-i"
                  << source3
                  << AccelArguments
                  << "-i"
                  << source
                  << "-i"
                  << source2
                  << AccelArguments
                  <<"-i"
                  << source1
                  << "-filter_complex"
                  << filter_4ch_1080p
                  << "-c:v"
                  << "h264_qsv"
                  << "-vol"
                  << "50"
                  << saveasFilename;
    }
}
    mVideoProcess->setProcessChannelMode(QProcess::MergedChannels);
    /**fix CVE-2022-25255 QProcess could execute a binary from the current working directory when not found in the PATH**/
    QString exeFilePath = QStandardPaths::findExecutable(program);

    if(!exeFilePath.isEmpty())
        mVideoProcess->start(program,arguments);
}


void Dialog::on_streamButton_clicked()
{
    qDebug() << "stream button is clicked";

    QString program = "ffmpeg/ffmpeg.exe";

    QStringList arguments;
    QString source = ui->fromLineEdit->text();
    QString source1 = ui->fromLineEdit_1->text();
    QString source2 = ui->fromLineEdit_2->text();
    QString source3 = ui->fromLineEdit_3->text();
    ui->startButton->setEnabled(false);
    streamison = true;

    if((source.isEmpty() && (!ui->radioButton->isChecked()))|| source3.isEmpty())
    {
        qDebug() << "At least 2 input2, background and foreground video";
        QMessageBox::information(this, tr("ffmpeg"), tr("请至少选择背景和前景输入"));
        ui->streamButton->setEnabled(true);
        return;
    }

    QStringList initArguments, initDebugArguments, AccelArguments, CameraArguments,streamArguments;
    initArguments << "-init_hw_device" << "qsv=qs:child_device_type=d3d11va";
    initDebugArguments << "-v" << "verbose" << "-init_hw_device" << "qsv=qs:child_device_type=d3d11va";
    AccelArguments << "-hwaccel" << "qsv" << "-hwaccel_device" << "qs" << "-c:v" << "h264_qsv";
    CameraArguments << "-rtbufsize" << "1024M" << "-f" << "dshow" << "-i" << Camera_device;
    //QString filter_2ch_4k = "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[main][overlay]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001,format=opencl,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv";
    //QString filter_4ch_4k = "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[2:v]hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv[pngoverlay];[3:v]vpp_qsv=w=1280:h=736,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay2];[main][overlay]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001[compo1];[compo1][overlay2]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv[compo3];[compo3][pngoverlay]overlay_qsv=x=2560:y=640";
    /****Configuration for sports****/
    //QString filter_2ch_1080p = "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[main][overlay]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001,format=opencl,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv";
    //QString filter_4ch_1080p = "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[2:v]hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv[pngoverlay];[3:v]vpp_qsv=w=640:h=352,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay2];[main][overlay]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001[compo1];[compo1][overlay2]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv[compo3];[compo3][pngoverlay]overlay_qsv=x=1400:y=320:w=480:h=480";
    /****Configuration for others ****/
    QString filter_2ch_1080p = "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[main][overlay]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03,format=opencl,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv";
    QString filter_4ch_1080p = "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[2:v]hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv[pngoverlay];[3:v]vpp_qsv=w=640:h=352,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay2];[main][overlay]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.030[compo1];[compo1][overlay2]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv[compo3];[compo3][pngoverlay]overlay_qsv=x=1400:y=320:w=480:h=480";

    QString filter_2ch_camera ="[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]fps=30,hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv,vpp_qsv=w=1920:h=1080:format=nv12,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[main][overlay]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03,format=opencl,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv,setpts=N/FRAME_RATE/TB";
    QString filter_4ch_camera ="[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]fps=30,hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv,vpp_qsv=w=1920:h=1080:format=nv12,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[2:v]hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv[pngoverlay];[3:v]vpp_qsv=w=640:h=352,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay2];[main][overlay]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03[compo1];[compo1][overlay2]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv[compo3];[compo3][pngoverlay]overlay_qsv=x=1400:y=320:w=480:h=480,setpts=N/FRAME_RATE/TB";

    streamArguments << "-r" << "30" << "-f" <<"flv" << "-ar" << "44100" << "-vol" << "50" << "-b:v" << "6M"<< "rtmp://127.0.0.1:1935/live";
    /* arguments supports 2 format
 * 1. background (color key) + forground
 * 2. background (color key) + forground + Roll Ad + close up Ad (colorkey)*/
 /**cmd:ffmpeg.exe -v verbose -init_hw_device qsv=qs:child_device_type=d3d11va -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -i ../../../../linux_video/output_4k_bg.mp4 -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -i ../../../../linux_video/output_4k_green.mp4 -filter_complex "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[main][overlay]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001,format=opencl,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv" -c:v h264_qsv 4k_output_2ch.mp4**/
    if (CameraisSelected)
    {
        // in camera mode, 2 source are supported only
        int SaveFrames;
        int defaultime = 10;
        if (ui->TimeinSecond->text().isEmpty())  //record 10 second by default, otherwise using the input timeinseconds
            SaveFrames = defaultime * 30;
            else
            SaveFrames = ui->TimeinSecond->text().toInt() * 30;
        /* Mode 1. background  + camer mode forground*/
        if(!source3.isEmpty() && ui->radioButton->isChecked() && source1.isEmpty() && source2.isEmpty())
        {
            arguments << initArguments
                      << AccelArguments
                      <<"-stream_loop"     /**Loop background infinitely*/
                      << "-1"
                      << "-i"
                      << source3
                      << CameraArguments
                      << "-filter_complex"
                      << filter_2ch_camera
                      << "-c:v"
                      << "h264_qsv"
                      << "-vframes"
                      << QString::number(SaveFrames)
                      << streamArguments;
        }

        /* Mode 2. background  + camer mode forground  + Roll Ad + close up Ad (colorkey)*/
        /**ffmpeg.exe -init_hw_device qsv=qs:child_device_type=d3d11va -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -stream_loop 2 -i C:/ffmpeg_src/linux_video/backgroud_1080.mp4 -rtbufsize 1024M -f dshow -i "video=Intel Virtual Camera" -i C:/ffmpeg_src/linux_video/intel.png -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -stream_loop 2 -i C:/Users/ouyang/Videos/2_hamburger/ad_burger.mp4 -filter_complex "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]fps=30,hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv,vpp_qsv=w=1920:h=1080:format=nv12,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[2:v]hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv[pngoverlay];[3:v]vpp_qsv=w=640:h=352,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay2];[main][overlay]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03[compo1];[compo1][overlay2]overlay_opencl=colorkey=1:color=#ab2f54:similarity=0.261:blend=0.03,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv[compo3];[compo3][pngoverlay]overlay_qsv=x=1400:y=320:w=480:h=480",setpts=N/FRAME_RATE/TB -c:v h264_qsv -b:v 6M -vframes 1000 -y 4ch_camera_burger_lp3.mp4**/

        if(!source3.isEmpty() && ui->radioButton->isChecked() && !source1.isEmpty() && !source2.isEmpty())
        {
            //to do: add 4 channel mode
            arguments << initArguments
                      << AccelArguments
                      <<"-stream_loop"
                      << "-1"
                      << "-i"
                      << source3
                      << CameraArguments
                      << "-i"
                      << source2
                      << AccelArguments
                      <<"-stream_loop"
                      << "-1"
                      << "-i"
                      << source1
                      << "-filter_complex"
                      << filter_4ch_camera
                      << "-c:v"
                      << "h264_qsv"
                      << "-vframes"
                      << QString::number(SaveFrames)
                      << streamArguments;
        }
    }
    else
    {
        if(!source.isEmpty() && !source3.isEmpty() && source1.isEmpty() && source2.isEmpty())
        {
        arguments << initArguments
                  << AccelArguments
                  << "-i"
                  << source3
                  << AccelArguments
                  << "-i"
                  << source
                  << "-filter_complex"
                  << filter_2ch_1080p
                  << "-c:v"
                  << "h264_qsv"
                  << streamArguments;
        }

    /**Case 2 Example command
    **./ffmpeg.exe -v verbose -init_hw_device qsv=qs:child_device_type=d3d11va -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -i ../../../../linux_video/backgroud_1080.mp4 -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -i ../../../../linux_video/green_1080.mp4 -i ../../../../linux_video/intel.png -hwaccel qsv -hwaccel_device qs -c:v h264_qsv -i ../../../../linux_video/green_1080.mp4 -filter_complex "[0:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[main];[1:v]hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay];[2:v]hwupload=derive_device=qsv:extra_hw_frames=16,format=qsv[pngoverlay];[3:v]vpp_qsv=w=640:h=352,hwmap=derive_device=d3d11va,format=d3d11,hwmap=derive_device=opencl[overlay2];[main][overlay]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001[compo1];[compo1][overlay2]overlay_opencl=colorkey=1:color=#bf684c:similarity=0.21:blend=0.001,hwmap=derive_device=d3d11va:reverse=1:extra_hw_frames=16,format=d3d11,hwmap=derive_device=qsv,format=qsv[compo3];[compo3][pngoverlay]overlay_qsv=x=1400:y=320:w=480:h=480" -c:v h264_qsv -r 30 -f flv rtmp://127.0.0.1:1935/live
    **/

    if(!source.isEmpty() && !source3.isEmpty() && !source1.isEmpty() && !source2.isEmpty())
    {
        arguments << initArguments
                  << AccelArguments
                  << "-i"
                  << source3
                  << AccelArguments
                  << "-i"
                  << source
                  << "-i"
                  << source2
                  << AccelArguments
                  <<"-i"
                  << source1
                  << "-filter_complex"
                  << filter_4ch_1080p
                  << "-c:v"
                  << "h264_qsv"
                  << streamArguments;
        }
    }

    mVideoProcess->setProcessChannelMode(QProcess::MergedChannels);
    /**fix CVE-2022-25255 QProcess could execute a binary from the current working directory when not found in the PATH**/
    QString exeFilePath = QStandardPaths::findExecutable(program);

    if(!exeFilePath.isEmpty())
        mVideoProcess->start(program,arguments);
    //qDebug() << "ffmpeg.exe" << arguments;
}

/***Delete all the widget except the first one***/
void Dialog::delitem()
{
    int item = 0;
    int count = ui->listWidget->count();
    item = count - 1;

    while (item > 0)
    {
        ui->listWidget->takeItem(item);
        qDebug() << "delete item: " << item;
        item--;
    }
}


void Dialog::on_ClearButton_clicked()
{
    /*****Clear the linetextEdit, remove thumbnail *****/

    if(!ui->fromLineEdit->text().isEmpty())
    {
        ui->fromLineEdit->clear();
    }

    if(!ui->fromLineEdit_1->text().isEmpty())
    {
        ui->fromLineEdit_1->clear();
    }
    if(!ui->fromLineEdit_2->text().isEmpty())
    {

        ui->fromLineEdit_2->clear();
    }
    if(!ui->fromLineEdit_3->text().isEmpty())
    {
        ui->fromLineEdit_3->clear();
    }
    if(ui->widget->m_cboxUrl->lineEdit())
    {
        ui->widget->m_cboxUrl->clearEditText();
    }
    if(!ui->toLineEdit->text().isEmpty())
    {
        ui->toLineEdit->clear();
    }
    if(!ui->TimeinSecond->text().isEmpty())
    {
        ui->TimeinSecond->clear();
    }

    CameraisSelected = false;
    ui->radioButton->setChecked(false);  //reset radio button
    ui->radioButton->setText("Camera");
    ui->radioButton->setCheckable(false);
    ui->radioButton->setCheckable(true);

    ui->fromLineEdit->setEnabled(true);
    ui->fromLineEdit->setReadOnly(false);

    delitem();
}

void Dialog::on_radioButton_clicked()
{
    QString path;
    qDebug() << "radio button is clicked";

    CameraisSelected = true;

    if (ui->radioButton->isChecked())
    {
        qDebug()<<"btn is checked";
    }

    ui->radioButton->setText("Virtual Camera Selected");

    /**Generate one thumbnail figure and display***/
    path = ":/images/camera.png";
    /**Display the thumbnail in list widget**/
    QListWidgetItem *item = new QListWidgetItem(QIcon(path),QString("前景Camera"));

    ui->listWidget->takeItem(1);
    ui->listWidget->insertItem(1, item);

    Camera_device = "video=Intel Virtual Camera";

    ui->fromLineEdit->setEnabled(false);
    ui->fromLineEdit->setReadOnly(true);
    ui->fromLineEdit->setFocusPolicy(Qt::NoFocus);
}

