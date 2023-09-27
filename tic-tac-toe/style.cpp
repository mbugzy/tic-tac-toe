
#include "style.h"




QString style::defButton()
{
    return "QPushButton {"
            "font-size: 20px;"
            "font-weight: bold;"
            "color: white;"
            "background-color: #FF7f27;"
            "border: 1px solid black;"
            "padding: 5px 5px;"
            "border-radius: 5px;"
            "}"
            "QPushButton:hover {"
            "background-color: #1d501e;"
            "}";
}


QString style::actButton()
{
    return "QPushButton {"
            "font-size: 20px;"
            "font-weight: bold;"
            "color: white;"
            "background-color: #2f7f3f;"
            "border: 1px solid black;"
            "padding: 5px 5px;"
            "border-radius: 5px;"
            "}";
}



QString style::areaButtonX()
{
    return "QPushButton{"
           "background-color:#ff0000"
           "}";
}

QString style::areaButtonO()
{
    return "QPushButton{"
           "background-color:#0000ff"
           "}";
}

QString style::areaButtonDefault()
{
    return "QPushButton{"
           "background-color:#cc00cc"
           "}"
           "QPushButton:hover {"
           "background-color: #800080;"
           "}";
}
QString style::clearButton()
{
    return "QAbstractButton::animateClick{"
           "background-color:#00ff00"
           "}";
}

QString style::backGrondWindow()
{
    return  "background-color:#ffff55";
}
