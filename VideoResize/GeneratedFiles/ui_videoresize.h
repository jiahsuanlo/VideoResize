/********************************************************************************
** Form generated from reading UI file 'videoresize.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEORESIZE_H
#define UI_VIDEORESIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoResizeClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *ed_src;
    QPushButton *bt_src;
    QLabel *label_2;
    QLineEdit *ed_dst;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *ed_width;
    QLabel *label_4;
    QLineEdit *ed_height;
    QCheckBox *ck_aspect;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *bt_start;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *VideoResizeClass)
    {
        if (VideoResizeClass->objectName().isEmpty())
            VideoResizeClass->setObjectName(QStringLiteral("VideoResizeClass"));
        VideoResizeClass->resize(1501, 591);
        verticalLayout = new QVBoxLayout(VideoResizeClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(VideoResizeClass);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        ed_src = new QLineEdit(VideoResizeClass);
        ed_src->setObjectName(QStringLiteral("ed_src"));

        gridLayout->addWidget(ed_src, 1, 0, 1, 1);

        bt_src = new QPushButton(VideoResizeClass);
        bt_src->setObjectName(QStringLiteral("bt_src"));

        gridLayout->addWidget(bt_src, 1, 1, 1, 1);

        label_2 = new QLabel(VideoResizeClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        ed_dst = new QLineEdit(VideoResizeClass);
        ed_dst->setObjectName(QStringLiteral("ed_dst"));

        gridLayout->addWidget(ed_dst, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(VideoResizeClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        ed_width = new QLineEdit(VideoResizeClass);
        ed_width->setObjectName(QStringLiteral("ed_width"));

        horizontalLayout_2->addWidget(ed_width);

        label_4 = new QLabel(VideoResizeClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        ed_height = new QLineEdit(VideoResizeClass);
        ed_height->setObjectName(QStringLiteral("ed_height"));

        horizontalLayout_2->addWidget(ed_height);

        ck_aspect = new QCheckBox(VideoResizeClass);
        ck_aspect->setObjectName(QStringLiteral("ck_aspect"));

        horizontalLayout_2->addWidget(ck_aspect);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bt_start = new QPushButton(VideoResizeClass);
        bt_start->setObjectName(QStringLiteral("bt_start"));

        horizontalLayout->addWidget(bt_start);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(VideoResizeClass);

        QMetaObject::connectSlotsByName(VideoResizeClass);
    } // setupUi

    void retranslateUi(QWidget *VideoResizeClass)
    {
        VideoResizeClass->setWindowTitle(QApplication::translate("VideoResizeClass", "ImageResize", 0));
        label->setText(QApplication::translate("VideoResizeClass", "Source Video File", 0));
        bt_src->setText(QApplication::translate("VideoResizeClass", "browse", 0));
        label_2->setText(QApplication::translate("VideoResizeClass", "Destination Video File Name", 0));
        label_3->setText(QApplication::translate("VideoResizeClass", "width", 0));
        label_4->setText(QApplication::translate("VideoResizeClass", "height", 0));
        ck_aspect->setText(QApplication::translate("VideoResizeClass", "fix aspect ratio", 0));
        bt_start->setText(QApplication::translate("VideoResizeClass", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoResizeClass: public Ui_VideoResizeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEORESIZE_H
