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

# MiniAudio
mkdir "${MA_TARGET}"

mf --f "${MA_ORIGIN}/LICENSE" --t "${MA_TARGET}/LICENSE"

mf --f "${MA_ORIGIN}/include" --t "${MA_TARGET}"

mf --f "${MA_ORIGIN}/release" --t "${MA_TARGET}"
mf --f "${MA_ORIGIN}/debug" --t "${MA_TARGET}"
