#!/bin/sh

# Move file for use with mf, read more at https://github.com/greeenlaser/personal-stash/tree/main/mf

set -e

#
# References
#

EXTERNAL_DIR=external

KH_ORIGIN=../kalaheaders
KH_TARGET=${EXTERNAL_DIR}/kalaheaders

MA_ORIGIN=../../_forks/miniaudio/_build
MA_TARGET=${EXTERNAL_DIR}/miniaudio

#
# Copy dependencies
#

# Always a fresh start
rm -rf "${EXTERNAL_DIR}"
mkdir "${EXTERNAL_DIR}"

# KalaHeaders
mkdir "${KH_TARGET}"

mf --f "${KH_ORIGIN}/README.md" --t "${KH_TARGET}/README.md"
mf --f "${KH_ORIGIN}/LICENSE.md" --t "${KH_TARGET}/LICENSE.md"

mf --f "${KH_ORIGIN}/include" --t "${KH_TARGET}"

# Miniaudio
mkdir "${MA_TARGET}"

if [ -d "${MA_ORIGIN}/release-windows" ]; then
    mf --f "${MA_ORIGIN}/release-windows" --t "${MA_TARGET}"
fi
if [ -d "${MA_ORIGIN}/release-windows-gnu" ]; then
    mf --f "${MA_ORIGIN}/release-windows-gnu" --t "${MA_TARGET}"
fi
if [ -d "${MA_ORIGIN}/release-linux" ]; then
    mf --f "${MA_ORIGIN}/release-linux" --t "${MA_TARGET}"
fi

if [ -d "${MA_ORIGIN}/debug-windows" ]; then
    mf --f "${MA_ORIGIN}/debug-windows" --t "${MA_TARGET}"
fi
if [ -d "${MA_ORIGIN}/debug-windows-gnu" ]; then
    mf --f "${MA_ORIGIN}/debug-windows-gnu" --t "${MA_TARGET}"
fi
if [ -d "${MA_ORIGIN}/debug-linux" ]; then
    mf --f "${MA_ORIGIN}/debug-linux" --t "${MA_TARGET}"
fi
