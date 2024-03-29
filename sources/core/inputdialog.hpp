#pragma once

#include <QDialog>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>

class VirtualPort;

class InputDialog : public QDialog {
    Q_OBJECT

public:
    InputDialog(QWidget* parent = nullptr);
    ~InputDialog() = default;

    void setSerialPort(VirtualPort* pComPort) noexcept;

    QString getComPort() const noexcept;
    QString getBaudRate() const noexcept;

private:
    void initializeWidget() noexcept;
    void addElements() noexcept;
    void fillComboBoxes() noexcept;

private slots:
    void dialogClose();

private:
    VirtualPort* m_pSerialPort;
    QComboBox* m_pTxtComPort;
    QComboBox* m_pTxtBaudRate;
};
