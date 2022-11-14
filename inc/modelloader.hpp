#ifndef CUBE3D_MODELLOADER_HPP_
#define CUBE3D_MODELLOADER_HPP_

#include <QtCore/QObject>
#include <QFileDialog>
#include <QShortcut>

class SceneModifier;

class ModelLoader
    :   public QWidget
{
    Q_OBJECT

public:
    explicit ModelLoader( QWidget* _parent = nullptr );
    ~ModelLoader() = default;

    QString getPathToModel() const;

    void setSceneModifier( SceneModifier* _sceneModifier );

public slots:
    void hotkeyClicked();

signals:
    void modelPathChanged();

private:
    void connectSignals();

    Q_DISABLE_COPY(ModelLoader)

    QString m_pathToModel;
    QShortcut* m_keyCtlD;
    SceneModifier* m_pSceneModifier;
};

#endif // CUBE3D_MODELLOADER_HPP_
