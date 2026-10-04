#include "CustomShelfPane.h"
#include "dzcontentmgr.h"
#include "dzapp.h"
#include <QInputDialog>
#include <QFileInfo>

CustomShelfPane::CustomShelfPane() : DzPane("Custom Asset Shelf")
{
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    
    // Left: Assets Grid Column
    QWidget *assetWidget = new QWidget(this);
    QVBoxLayout *assetLayout = new QVBoxLayout(assetWidget);
    m_addAssetBtn = new QPushButton("+ Add Selected Content", assetWidget);
    assetLayout->addWidget(m_addAssetBtn);
    
    m_gridContainer = new QWidget(assetWidget);
    m_gridLayout = new QGridLayout(m_gridContainer);
    assetLayout->addWidget(m_gridContainer);
    
    // Middle: Child Tabs Column
    QWidget *childWidget = new QWidget(this);
    QVBoxLayout *childLayout = new QVBoxLayout(childWidget);
    m_childList = new QListWidget(childWidget);
    m_addChildBtn = new QPushButton("+ New Sub Tab", childWidget);
    childLayout->addWidget(m_childList);
    childLayout->addWidget(m_addChildBtn);
    
    // Right: Mother Tabs Column
    QWidget *motherWidget = new QWidget(this);
    QVBoxLayout *motherLayout = new QVBoxLayout(motherWidget);
    m_motherList = new QListWidget(motherWidget);
    m_addMotherBtn = new QPushButton("+ New Main Tab", motherWidget);
    motherLayout->addWidget(m_motherList);
    motherLayout->addWidget(m_addMotherBtn);
    
    mainLayout->addWidget(assetWidget);
    mainLayout->addWidget(childWidget);
    mainLayout->addWidget(motherWidget);
    
    connect(m_addMotherBtn, SIGNAL(clicked()), this, SLOT(addMotherTab()));
    connect(m_addChildBtn, SIGNAL(clicked()), this, SLOT(addChildTab()));
    connect(m_addAssetBtn, SIGNAL(clicked()), this, SLOT(addSelectedAsset()));
}

CustomShelfPane::~CustomShelfPane() {}

void CustomShelfPane::addMotherTab() {
    bool ok;
    QString text = QInputDialog::getText(this, "Main Category", "Category Name:", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        m_motherList->addItem(text);
    }
}

void CustomShelfPane::addChildTab() {
    if (!m_motherList->currentItem()) return;
    bool ok;
    QString text = QInputDialog::getText(this, "Sub Category", "Sub Tab Name:", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        m_childList->addItem(text);
    }
}

void CustomShelfPane::addSelectedAsset() {
    DzContentMgr *contentMgr = dzApp->getContentMgr();
    if (contentMgr) {
        QString selFile = contentMgr->getSelectedFile();
        if (!selFile.isEmpty()) {
            QFileInfo fileInfo(selFile);
            QPushButton *btn = new QPushButton(fileInfo.baseName(), m_gridContainer);
            int count = m_gridLayout->count();
            m_gridLayout->addWidget(btn, count / 3, count % 3);
        }
    }
}
