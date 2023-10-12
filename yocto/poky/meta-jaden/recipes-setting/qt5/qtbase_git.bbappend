SUMMARY = "qt recipes"
DESCRIPTION = "for qt"
LICENSE = "CLOSED"

PACKAGECONFIG:append = " eglfs fontconfig gles2"
DEPENDS += "userland"
