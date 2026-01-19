# AGL configuration include file for Toradex Apalis i.MX8
# Adapted from meta-nxp-agl for Toradex BSP layers

require conf/include/agl_imx-common.inc

DISTRO_FEATURES:append = " agl-medium-arm-compiler"

# Force use of Toradex BSP and kernel
IMX_DEFAULT_BSP = "nxp"
IMX_DEFAULT_KERNEL:${MACHINE} = "linux-toradex"

# Prefer Toradex U-Boot and Linux
PREFERRED_PROVIDER_virtual/kernel = "linux-toradex"
PREFERRED_PROVIDER_virtual/kernel:preempt-rt = "linux-toradex"
PREFERRED_VERSION_linux-toradex = "5.15%"

PREFERRED_PROVIDER_virtual/bootloader = "u-boot-toradex"
PREFERRED_PROVIDER_u-boot = "u-boot-toradex"
PREFERRED_VERSION_u-boot-toradex = "2022.04%"

# Use Toradex ATF (Arm Trusted Firmware)
PREFERRED_PROVIDER_imx-atf = "imx-atf"  
ATF_PLATFORM = "imx8qm"

# Enable Tezi (Toradex Easy Installer) image generation
IMAGE_CLASSES:append = " image_type_tezi"
IMAGE_FSTYPES:append = " teziimg"

# Initramfs configuration
AGL_DEFAULT_INITRAMFS_FSTYPES := ""

# Firmware and drivers recommended by Apalis i.MX8 machine config
MACHINE_EXTRA_RRECOMMENDS:append = " mwifiexconf linux-firmware-pcie8997 firmware-imx-hdmi"

# U-Boot version alignment
PREFERRED_VERSION_u-boot ?= "2022.04"

# Fix circular dependency with netboot
IMAGE_FSTYPES:remove:pn-initramfs-netboot-image = "teziimg"

# Use device-tree-overlays
PREFERRED_PROVIDER_virtual/dtb = "device-tree-overlays"

# Optional: Wi-Fi or UART helper if needed later
# MACHINE_FEATURES:append = " bcm4356"
# MACHINE_EXTRA_RRECOMMENDS:append = " hci-uart-helper"
