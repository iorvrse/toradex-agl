# This must be parsed after qt5, etc. layers so that they are correctly
# recognized by meta-freescale/dynamic-layers
BBLAYERS =+ "\
  ${METADIR}/bsp/meta-arm/meta-arm \
  ${METADIR}/bsp/meta-arm/meta-arm-toolchain \
  ${METADIR}/bsp/meta-freescale \
  ${METADIR}/bsp/meta-freescale-3rdparty \
  ${METADIR}/bsp/meta-freescale-distro \
  ${METADIR}/external/meta-toradex-bsp-common \
  ${METADIR}/external/meta-toradex-distro \
  ${METADIR}/external/meta-toradex-nxp \
  ${METADIR}/meta-toradex-agl \
  "
