#include "../../include/ui/aim65proxy.h"

Aim65Proxy::Aim65Proxy(Aim65 *aim65, QObject *parent) : QObject(parent), UiProxy()
{
    this->m_aim65 = std::shared_ptr<Aim65>(Aim65::GetInstance());
    this->m_aim65->Initialise();
    this->RegisterProxy();
}

Aim65Proxy::~Aim65Proxy()
{
}

void Aim65Proxy::RegisterProxy()
{
    UiProxyCollection::GetInstance()->InsertAim65Proxy(std::shared_ptr<Aim65Proxy>(this));
}

void Aim65Proxy::Start()
{
    //Cpu::GetInstance()->Reset();
    Cpu::GetInstance()->Run();
}

void Aim65Proxy::SetResetButton(bool newState)
{
    if (newState == true)
    {
        Cpu::GetInstance()->Reset();
        Start();
    }
    else
    {
        Cpu::GetInstance()->Halt();
    }

    this->m_aim65->SetPowerSwitch(newState);
}

bool Aim65Proxy::GetResetButton() const
{
    return true;
}
