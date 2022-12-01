/******************************************************************************\
 * Copyright © 2022 Intel Corporation

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

\**********************************************************************************/
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void paintEvent(QPaintEvent *e);
private slots:
    void on_fileOpenButton_clicked();

    void on_fileOpenButton_1_clicked();

    void on_fileOpenButton_2_clicked();

    void on_fileOpenButton_3_clicked();

    void on_startButton_clicked();

    void VideoprocessStarted();

    void VideoprocessOutputMsg();

    void Videoprocessended();

    void on_streamButton_clicked();

    QString thumbnail_generate(QString filename, int i);

    void on_ClearButton_clicked();

    void on_radioButton_clicked();

private:
    Ui::Dialog *ui;
    QProcess *mVideoProcess;
    QString OutputString;
    bool streamison;
    bool CameraisSelected;
    QString Camera_device;
    void delitem();
};
#endif // DIALOG_H
