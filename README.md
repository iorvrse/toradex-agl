# Toradex AGL Integration (Quillback 17.1.13)

This repository provides a minimal setup to build **Automotive Grade Linux (AGL) Quillback 17.1.13** for **Toradex platforms**, specifically targeting **Apalis i.MX8**, by integrating Toradex BSP layers into the AGL build environment using a custom repo manifest.

## Repository Contents

```
.
├── meta-toradex-agl/
│   └── AGL integration layer for Toradex platforms
│
└── toradex-5.15_quillback-17.1.13.xml
    └── Custom repo manifest extending AGL with Toradex BSP layers
```

## Overview

- Uses **AGL Quillback 17.1.13**
- Based on **Yocto Kirkstone**
- Linux kernel **5.15**
- Keeps **AGL as the distro**
- Uses Toradex layers strictly for BSP and hardware enablement

This repository does **not** replace AGL core components or distro configuration.

---

## Requirements

- `repo` tool
- Git
- Standard AGL build dependencies

Refer to the official AGL documentation for host setup requirements.

---

## Getting Started

### Initialize the repo using the custom manifest

```bash
mkdir toradex-agl
cd toradex-agl

repo init -u https://github.com/iorvrse/toradex-agl.git -b main -m toradex-5.15_quillback-17.1.13.xml
```

### Sync repositories

```bash
repo sync
```

This will fetch:
- AGL core layers
- Yocto / OpenEmbedded dependencies
- Toradex BSP layers under `external/`

---

## Build Setup

### Source the AGL build environment

```bash
source meta-agl/scripts/aglsetup.sh -m apalis-imx8 -b build agl-all-feature
```

Where:
- `apalis-imx8` selects the Toradex Apalis i.MX8 machine
- `build` is the build directory
- `agl-all-feature` is the AGL reference feature-rich image

---

## Build the Image

```bash
bitbake agl-demo-flutter
```

The generated images will be available in:

```
build/tmp/deploy/images/apalis-imx8/
```

---

## Notes

- This setup uses the **AGL distro**, not the Toradex distro.
- Toradex demo images and distro configurations are intentionally not used.
- Layer priority and compatibility follow AGL Quillback conventions.
- Additional Toradex platforms may require further adjustments.

---

## Supported Platforms

- Toradex Apalis i.MX8

---

## References

- Automotive Grade Linux: https://www.automotivelinux.org  
- AGL Documentation: https://docs.automotivelinux.org  
- Toradex Developer Documentation: https://developer.toradex.com  
