#include "modelloader.hpp"
#include "scenemodifier.hpp"

#include <QShortcut>

ModelLoader::ModelLoader(QWidget* parent)
    : QWidget(parent), m_pSceneModifier(nullptr) {
    m_keyCtlD = new QShortcut(this);
    m_keyCtlD->setKey(Qt::CTRL + Qt::Key_Q);
}

QString ModelLoader::getPathToModel() const {
    return m_pathToModel;
}

void ModelLoader::connectSignals() {
    connect(m_keyCtlD, &QShortcut::activated, this, &ModelLoader::hotkeyClicked);

    connect(this, &ModelLoader::modelPathChanged,
        m_pSceneModifier, &SceneModifier::onModelPathChanged);
}

void ModelLoader::setSceneModifier(SceneModifier* sceneModifier) {
    m_pSceneModifier = sceneModifier;
    connectSignals();
}

void ModelLoader::hotkeyClicked() {
    QFileDialog filePicker;
    filePicker.setNameFilter(tr("3D models files(*.obj)"));

    m_pathToModel = filePicker.getOpenFileName();

    if (!m_pathToModel.isEmpty())
        emit modelPathChanged();
}
