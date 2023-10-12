SUMMARY = "My image for yocto"
inherit my-rpi-image

LINGUAS_KO_KR = "ko-kr"
LINGUAS_EN_US = "en-us"
IMAGE_LINGUAS = "${LINGUAS_KO_KR} ${LINGUAS_EN_US}"
IMAGE_OVERHEAD_FACTOR = "1.3"

inherit extrausers populate_sdk populate_sdk_qt5

EXTRA_USERS_PARAMS = "\
 	groupadd seame; \
	useradd -p \$(openssl passwd 1234) team6; \
       	useradd -a -G sudo team6; \
	useradd -g seame team6; \
"	

