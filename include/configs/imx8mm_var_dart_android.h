/*
 * Copyright 2018 NXP
 * Copyright 2019 Variscite Ltd.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __MX8MM_VAR_DART_ANDROID_H
#define __MX8MM_VAR_DART_ANDROID_H

#define CONFIG_BCB_SUPPORT
#define CONFIG_CMD_READ

#define CONFIG_ANDROID_AB_SUPPORT
#define CONFIG_AVB_SUPPORT
#define CONFIG_SUPPORT_EMMC_RPMB
#define CONFIG_SYSTEM_RAMDISK_SUPPORT
#define CONFIG_AVB_FUSE_BANK_SIZEW 0
#define CONFIG_AVB_FUSE_BANK_START 0
#define CONFIG_AVB_FUSE_BANK_END 0
#define CONFIG_FASTBOOT_LOCK
#define FSL_FASTBOOT_FB_DEV "mmc"

#ifdef CONFIG_SYS_MALLOC_LEN
#undef CONFIG_SYS_MALLOC_LEN
#define CONFIG_SYS_MALLOC_LEN           (96 * SZ_1M)
#endif

#define CONFIG_USB_FUNCTION_FASTBOOT
#define CONFIG_CMD_FASTBOOT
#define CONFIG_ANDROID_BOOT_IMAGE
#define CONFIG_FASTBOOT_FLASH
#define CONFIG_FASTBOOT_STORAGE_MMC

#define CONFIG_FSL_FASTBOOT
#define CONFIG_ANDROID_RECOVERY

#define CONFIG_FASTBOOT_BUF_ADDR   CONFIG_SYS_LOAD_ADDR
#define CONFIG_FASTBOOT_BUF_SIZE   0x19000000

#define CONFIG_CMD_BOOTA
#define CONFIG_SUPPORT_RAW_INITRD
#define CONFIG_SERIAL_TAG

#undef CONFIG_EXTRA_ENV_SETTINGS
#undef CONFIG_BOOTCOMMAND

#define CONFIG_EXTRA_ENV_SETTINGS		\
	"splashpos=m,m\0"			\
	"fdt_high=0xffffffffffffffff\0"		\
	"initrd_high=0xffffffffffffffff\0"	\
	"bootargs=" \
		"console=ttymxc0,115200 " \
		"earlycon=ec_imx6q,0x30860000,115200 " \
		"init=/init " \
		"androidboot.console=ttymxc0 " \
		"consoleblank=0 " \
		"androidboot.hardware=freescale " \
		"cma=800M " \
		"firmware_class.path=/vendor/firmware " \
		"transparent_hugepage=never " \
		"androidboot.primary_display=imx-drm\0"

/* Enable mcu firmware flash */
#ifdef CONFIG_FLASH_MCUFIRMWARE_SUPPORT
#define ANDROID_MCU_FRIMWARE_DEV_TYPE DEV_MMC
#define ANDROID_MCU_FIRMWARE_START 0x500000
#define ANDROID_MCU_FIRMWARE_SIZE  0x40000
#define ANDROID_MCU_FIRMWARE_HEADER_STACK 0x20020000
#endif

#ifdef CONFIG_FSL_CAAM_KB
#undef CONFIG_FSL_CAAM_KB
#endif
#define AVB_AB_I_UNDERSTAND_LIBAVB_AB_IS_DEPRECATED

#ifdef CONFIG_IMX_TRUSTY_OS
#define AVB_RPMB
#define KEYSLOT_HWPARTITION_ID 2
#define KEYSLOT_BLKS             0x1FFF
#define NS_ARCH_ARM64 1

#ifdef CONFIG_SPL_BUILD
#undef CONFIG_BLK
#endif

#endif

#endif /* __MX8MM_VAR_DART_ANDROID_H */
