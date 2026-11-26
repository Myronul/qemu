#include "qemu/osdep.h"
#include "qapi/error.h"
#include "qemu/module.h"
#include "hw/arm/boot.h"
#include "system/address-spaces.h"
#include "hw/core/qdev-properties.h"
#include "hw/core/qdev-clock.h"
#include "hw/misc/unimp.h"
#include "system/system.h"

#define TYPE_XMC_4500_SOC "xmc4500_soc"
OBJECT_DECLARE_SIMPLE_TYPE(xmc4500State, XMC4500_SOC)

typedef struct xmc4500State
{
    MachineState parentObj;
    ARMv7MState   mcu;
    struct arm_boot_info bootinfo;
}xmc4500State;

static void xmc4500_soc_init(MachineState* machine)
{
    xmc4500State* s = XMC4500_SOC(machine);
    deviceState* nvic;
    Clock* sysClk;
    Clock* refClk;

    object_initialize_child(OBJECT(s), "mcu", &s->mcu, TYPE_ARMV7M);
}