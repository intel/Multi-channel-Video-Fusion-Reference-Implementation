/******************************************************************************\
 * Copyright © 2022 Intel Corporation

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

\**********************************************************************************/
#include "dialog.h"

#include <QApplication>
#include <QFile>
#include <QIcon>
#include <QtAVWidgets>
#include "playerwindow.h"

int main(int argc, char *argv[])
{
    QtAV::Widgets::registerRenderers();
    QApplication a(argc, argv);

    Dialog w;
    w.setWindowTitle("图像融合Demo");
    w.setWindowIcon(QIcon(":/images/bg.png"));
    w.setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMaximizeButtonHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);

    QFile qss(":/ElegantDark.qss");

    QFont f("Microsoft Yahei",10);

    if(qss.open(QFile::ReadOnly))
    {
        qDebug("open Success");
        QString style= QLatin1String(qss.readAll());
        a.setStyleSheet(style);
    }
    else
        qDebug("open failed");

    a.setFont(f);
    w.show();
    return a.exec();
}
