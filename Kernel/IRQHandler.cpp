#include "IRQHandler.h"
#include "i386.h"
#include "PIC.h"

IRQHandler::IRQHandler(byte irq)
    : m_irq_number(irq)
{
    register_irq_handler(m_irq_number, *this);
}

IRQHandler::~IRQHandler()
{
    unregister_irq_handler(m_irq_number, *this);
}

void IRQHandler::enable_irq()
{
    PIC::enable(m_irq_number);
}

void IRQHandler::disable_irq()
{
    PIC::disable(m_irq_number);
}

