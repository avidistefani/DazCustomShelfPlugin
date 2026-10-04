#ifndef CUSTOM_SHELF_PANE_H
#define CUSTOM_SHELF_PANE_H

#include "dzpane.h"
#include <QListWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

class CustomShelfPane : public DzPane {
    Q_OBJECT
public:
    CustomShelfPane();
    ~CustomShelfPane();

private slots:
    void addMotherTab();
    void addChildTab();
    void addSelectedAsset();

private:
    QListWidget *m_motherList;
    QListWidget *m_childList;
    QPushButton *m_addMotherBtn;
    QPushButton *m_addChildBtn;
    QPushButton *m_addAssetBtn;
    QWidget *m_gridContainer;
    QGridLayout *m_gridLayout;
};

#endif // CUSTOM_SHELF_PANE_H
