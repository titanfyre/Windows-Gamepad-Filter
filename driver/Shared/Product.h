#pragma once
// Build identity and immutable family boundary for this separate product.
// This header is also directly testable outside the kernel.
#define IC_PRODUCT_SERVICE L"WindowsGamepadFilter"
#define IC_PRODUCT_XUSB_HID_PARENT_VALUE L"WindowsGamepadFilterXusbHidParent"
#define IC_PRODUCT_XUSB_PARENT_VALUE L"WindowsGamepadFilterXusbParent"
#define IC_PRODUCT_CONTROL_HWID L"ROOT\\WindowsGamepadFilterControl"
#define IC_PRODUCT_NT_DEVICE L"\\Device\\WindowsGamepadFilter"
#define IC_PRODUCT_DOS_DEVICE L"\\DosDevices\\WindowsGamepadFilter"
#define IC_PRODUCT_TRIAL_SLOT 2u
#define IC_PRODUCT_TRIAL_KEY L"\\Registry\\Machine\\HARDWARE\\WindowsGamepadFilterTrial"
#ifndef IC_PRODUCT_INPUT_MASK
#define IC_PRODUCT_INPUT_MASK 0u
#endif
#ifndef IC_PRODUCT_CONTROLLER_MASK
#define IC_PRODUCT_CONTROLLER_MASK 15u
#endif
#ifndef IC_PRODUCT_HAS_KEYBOARD_MOUSE
#define IC_PRODUCT_HAS_KEYBOARD_MOUSE 0
#endif
#ifndef IC_PRODUCT_HAS_CONTROLLERS
#define IC_PRODUCT_HAS_CONTROLLERS 1
#endif
#define IC_PRODUCT_STREAM_MASK (IC_PRODUCT_INPUT_MASK | (IC_PRODUCT_CONTROLLER_MASK << 2))
#define IC_PRODUCT_HID_GUID {0x61c9e72c,0xc585,0x5c0d,{0x8f,0xd3,0x5c,0x1e,0xb8,0x30,0xd2,0x53}}
#define IC_PRODUCT_XUSB_GUID {0xd1fec4e2,0x31db,0x5f18,{0xa0,0xce,0x03,0x10,0x32,0x0c,0x0c,0xc2}}
#define IC_PRODUCT_XINPUTHID_GUID {0xc71ae5f9,0x719c,0x569a,{0xb3,0xb2,0x52,0x8f,0x0e,0x34,0xf4,0x38}}
#define IC_PRODUCT_GIP_GUID {0xe80a988d,0x4f9c,0x50b4,{0xbf,0x2a,0xf9,0x7a,0x2d,0xce,0x47,0xfc}}
#define IC_PRODUCT_XUSB_MIRROR_GUID {0x43b486da,0x7b4c,0x5316,{0xaa,0xb6,0xb6,0x13,0xdc,0xe4,0x7d,0x7f}}
static __inline int IcProductTypeAllowed(unsigned int type) {
    return type>=1 && type<=6 && (IC_PRODUCT_STREAM_MASK & (1u<<(type-1)))!=0;
}
static __inline int IcProductCreateMasksAllowed(unsigned int input,unsigned int controllers) {
    return !(input & ~IC_PRODUCT_INPUT_MASK) && !(controllers & ~IC_PRODUCT_CONTROLLER_MASK);
}
// Function numbers are the pointer-free protocol's CTL_CODE function field.
// Unknown/common functions keep the normal control dispatch validation.
static __inline int IcProductIoctlFunctionAllowed(unsigned int fn) {
    switch(fn) {
    case 0xA01:case 0xA03:case 0xA07:
        return (IC_PRODUCT_INPUT_MASK & 1u)!=0;
    case 0xA02:case 0xA04:case 0xA08:
        return (IC_PRODUCT_INPUT_MASK & 2u)!=0;
    case 0xA09:case 0xA0A:case 0xA0B:case 0xA0C:case 0xA0D:
        return (IC_PRODUCT_CONTROLLER_MASK & 1u)!=0;
    case 0xA10:case 0xA11:case 0xA12:case 0xA13:case 0xA14:case 0xA15:
        return (IC_PRODUCT_CONTROLLER_MASK & 2u)!=0;
    case 0xA17:case 0xA18:case 0xA19:case 0xA1A:case 0xA1B:
        return (IC_PRODUCT_CONTROLLER_MASK & 4u)!=0;
    case 0xA20:case 0xA21:case 0xA22:case 0xA23:case 0xA24:case 0xA25:
    case 0xA29:case 0xA2A:case 0xA2B:
        return (IC_PRODUCT_CONTROLLER_MASK & 8u)!=0;
    case 0xA30:case 0xA31:case 0xA32:case 0xA33:
        return IC_PRODUCT_HAS_CONTROLLERS;
    default:return 1;
    }
}

