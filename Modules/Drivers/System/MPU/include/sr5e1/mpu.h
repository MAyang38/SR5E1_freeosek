/****************************************************************************
 *
 * Copyright (c) 2022 STMicroelectronics - All Rights Reserved
 *
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *****************************************************************************/
/**
 * @file    mpu.h
 * @brief   SR5E1 MPU header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup MPU
 * @ingroup SYSTEM
 * @{
 */

#ifndef _MPU_H_
#define _MPU_H_

#include <platform.h>
#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/**
 * @enum mpu_control_t
 * MPU Control type.
 */
typedef enum {
    MPU_CTRL_HFNMI_PRIVDEF_NONE    = 0x0UL,                                             /**< MPU disabled during hard fault, NMI, and FAULTMASK handlers. Privileges sw accesses disabled.                     */
    MPU_CTRL_HFNMI_ENABLED         = MPU_CTRL_HFNMIENA_Msk,                             /**< MPU enabled during hard fault, NMI, and FAULTMASK handlers.                                                       */
    MPU_CTRL_PRIVDEF_ENABLED       = MPU_CTRL_PRIVDEFENA_Msk,                           /**< Privileged sw accesses enabled to default memory map.                                                             */
    MPU_CTRL_HFNMI_PRIVDEF_ENABLED = (MPU_CTRL_HFNMIENA_Msk | MPU_CTRL_PRIVDEFENA_Msk)  /**< MPU enabled during hard fault, NMI, and FAULTMASK handlers. Privileged sw accesses enabled to default memory map. */
} mpu_control_t;

/**
 * @enum mpu_reg_enable_t
 * MPU region enable type.
 */
typedef enum {
    MPU_REG_DISABLE = 0U,   /**< MPU Region disabled */
    MPU_REG_ENABLE  = 1U    /**< MPU Region enabled  */
} mpu_reg_enable_t;

/**
 * @enum mpu_reg_number_t
 * MPU region number type.
 */
typedef enum {
    MPU_REG_NUMBER0  = 0U,   /**< MPU Region number 0  */
    MPU_REG_NUMBER1  = 1U,   /**< MPU Region number 1  */
    MPU_REG_NUMBER2  = 2U,   /**< MPU Region number 2  */
    MPU_REG_NUMBER3  = 3U,   /**< MPU Region number 3  */
    MPU_REG_NUMBER4  = 4U,   /**< MPU Region number 4  */
    MPU_REG_NUMBER5  = 5U,   /**< MPU Region number 5  */
    MPU_REG_NUMBER6  = 6U,   /**< MPU Region number 6  */
    MPU_REG_NUMBER7  = 7U,   /**< MPU Region number 7  */
    MPU_REG_NUMBER8  = 8U,   /**< MPU Region number 8  */
    MPU_REG_NUMBER9  = 9U,   /**< MPU Region number 9  */
    MPU_REG_NUMBER10 = 10U,  /**< MPU Region number 10 */
    MPU_REG_NUMBER11 = 11U,  /**< MPU Region number 11 */
    MPU_REG_NUMBER12 = 12U,  /**< MPU Region number 12 */
    MPU_REG_NUMBER13 = 13U,  /**< MPU Region number 13 */
    MPU_REG_NUMBER14 = 14U,  /**< MPU Region number 14 */
    MPU_REG_NUMBER15 = 15U   /**< MPU Region number 15 */
} mpu_reg_number_t;

/**
 * @enum mpu_reg_size_t
 * MPU region size type.
 */
typedef enum {
    MPU_REG_SIZE_32B   = 4U,    /**< MPU Region size = 32B   */
    MPU_REG_SIZE_64B   = 5U,    /**< MPU Region size = 64B   */
    MPU_REG_SIZE_128B  = 6U,    /**< MPU Region size = 128B  */
    MPU_REG_SIZE_256B  = 7U,    /**< MPU Region size = 256B  */
    MPU_REG_SIZE_512B  = 8U,    /**< MPU Region size = 512B  */
    MPU_REG_SIZE_1KB   = 9U,    /**< MPU Region size = 1KB   */
    MPU_REG_SIZE_2KB   = 10U,   /**< MPU Region size = 2KB   */
    MPU_REG_SIZE_4KB   = 11U,   /**< MPU Region size = 4KB   */
    MPU_REG_SIZE_8KB   = 12U,   /**< MPU Region size = 8KB   */
    MPU_REG_SIZE_16KB  = 13U,   /**< MPU Region size = 16KB  */
    MPU_REG_SIZE_32KB  = 14U,   /**< MPU Region size = 32KB  */
    MPU_REG_SIZE_64KB  = 15U,   /**< MPU Region size = 64KB  */
    MPU_REG_SIZE_128KB = 16U,   /**< MPU Region size = 128KB */
    MPU_REG_SIZE_256KB = 17U,   /**< MPU Region size = 256KB */
    MPU_REG_SIZE_512KB = 18U,   /**< MPU Region size = 512KB */
    MPU_REG_SIZE_1MB   = 19U,   /**< MPU Region size = 1MB   */
    MPU_REG_SIZE_2MB   = 20U,   /**< MPU Region size = 2MB   */
    MPU_REG_SIZE_4MB   = 21U,   /**< MPU Region size = 4MB   */
    MPU_REG_SIZE_8MB   = 22U,   /**< MPU Region size = 8MB   */
    MPU_REG_SIZE_16MB  = 23U,   /**< MPU Region size = 16MB  */
    MPU_REG_SIZE_32MB  = 24U,   /**< MPU Region size = 32MB  */
    MPU_REG_SIZE_64MB  = 25U,   /**< MPU Region size = 64MB  */
    MPU_REG_SIZE_128MB = 26U,   /**< MPU Region size = 128MB */
    MPU_REG_SIZE_256MB = 27U,   /**< MPU Region size = 256MB */
    MPU_REG_SIZE_512MB = 28U,   /**< MPU Region size = 512MB */
    MPU_REG_SIZE_1GB   = 29U,   /**< MPU Region size = 1GB   */
    MPU_REG_SIZE_2GB   = 30U,   /**< MPU Region size = 2GB   */
    MPU_REG_SIZE_4GB   = 31U    /**< MPU Region size = 4GB   */
} mpu_reg_size_t;

/**
 * @enum mpu_reg_tex_t
 * MPU type extension type.
 */
typedef enum {
    MPU_REG_TEX_LEVEL0 = 0U,   /**< MPU TEX Level 0 */
    MPU_REG_TEX_LEVEL1 = 1U,   /**< MPU TEX Level 1 */
    MPU_REG_TEX_LEVEL2 = 2U,   /**< MPU TEX Level 2 */
    MPU_REG_TEX_LEVEL4 = 4U    /**< MPU TEX Level 4 */
} mpu_reg_tex_t;


/**
 * @enum mpu_reg_ap_t
 * MPU region access permission type.
 */
typedef enum {
    MPU_REG_NO_ACCESS   = 0U,   /**< All accesses generate a permission fault                    */
    MPU_REG_PRIV_RW     = 1U,   /**< Access from privileged software only                        */
    MPU_REG_PRIV_RW_URO = 2U,   /**< Writes by unprivileged software generate a permission fault */
    MPU_REG_FULL_ACCESS = 3U,   /**< Full access                                                 */
    MPU_REG_PRIV_RO     = 5U,   /**< Reads by privileged software only                           */
    MPU_REG_PRIV_RO_URO = 6U    /**< Read only, by privileged or unprivileged software           */
} mpu_reg_ap_t;

/**
 * @enum mpu_reg_xn_t
 * MPU region instruction access disable type.
 */
typedef enum {
    MPU_REG_INSTRUCTION_ACCESS_ENABLE  = 0U,   /**< MPU instruction access enabled  */
    MPU_REG_INSTRUCTION_ACCESS_DISABLE = 1U    /**< MPU instruction access disabled */
} mpu_reg_xn_t;

/**
 * @enum mpu_reg_s_t
 * MPU region shareable type.
 */
typedef enum {
    MPU_REG_NOT_SHAREABLE = 0U,   /**< MPU Region not shareable */
    MPU_REG_SHAREABLE     = 1U    /**< MPU Region shareable     */
} mpu_reg_s_t;

/**
 * @enum mpu_reg_c_t
 * MPU region cacheable type.
 */
typedef enum {
    MPU_REG_NOT_CACHEABLE = 0U,   /**< MPU Region not cacheable */
    MPU_REG_CACHEABLE     = 1U    /**< MPU Region cacheable     */
} mpu_reg_c_t;

/**
 * @enum mpu_reg_b_t
 * MPU region bufferable type.
 */
typedef enum {
    MPU_REG_NOT_BUFFERABLE = 0U,   /**< MPU Region not bufferable */
    MPU_REG_BUFFERABLE     = 1U    /**< MPU Region bufferable     */
} mpu_reg_b_t;

/**
 * @brief   Type of an MPU region configuration.
 */
typedef struct mpu_region_config mpu_region_config_t;

/**
 * @brief   MPU region configuration structure.
 */
struct mpu_region_config {
    /**
     * @brief   MPU region status (enable or not).
     */
    mpu_reg_enable_t         enable;
    /**
     * @brief   Number of MPU region to configure.
     */
    mpu_reg_number_t         number;
    /**
     * @brief   Base address of MPU region.
     */
    uint32_t                 base_address;
    /**
     * @brief   Size of MPU region to configure.
     */
    mpu_reg_size_t           size;
    /**
     * @brief   Mask that specifies if the MPU subregions are disabled or not.
     */
    uint8_t                  subregion_disable;
    /**
     * @brief   Type Ext of MPU region.
     */
    mpu_reg_tex_t            type_ext;
    /**
     * @brief   Access permissions of MPU region.
     */
    mpu_reg_ap_t             access_permission;
    /**
     * @brief   Flag that specifies if instruction access is disabled or not.
     */
    mpu_reg_xn_t             instruction_disable;
    /**
     * @brief   Flag that specifies if the MPU region is shareable or not.
     */
    mpu_reg_s_t              shareable;
    /**
     * @brief   Flag that specifies if the MPU region is cacheable or not.
     */
    mpu_reg_c_t              cacheable;
    /**
     * @brief   Flag that specifies if the MPU region is bufferable or not.
     */
    mpu_reg_b_t              bufferable;
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/**
 * @name    MPU Subregion enable/disable
 * @{
 */
#define MPU_REG_SUBREG_ENABLE_ALL           0x00U
#define MPU_REG_SUBREG_DISABLE_ALL          0xFFU
#define MPU_REG_SUBREG_ENABLE(n)            (0U << n)
#define MPU_REG_SUBREG0_ENABLE              MPU_REG_SUBREG_ENABLE(0)
#define MPU_REG_SUBREG1_ENABLE              MPU_REG_SUBREG_ENABLE(1)
#define MPU_REG_SUBREG2_ENABLE              MPU_REG_SUBREG_ENABLE(2)
#define MPU_REG_SUBREG3_ENABLE              MPU_REG_SUBREG_ENABLE(3)
#define MPU_REG_SUBREG4_ENABLE              MPU_REG_SUBREG_ENABLE(4)
#define MPU_REG_SUBREG5_ENABLE              MPU_REG_SUBREG_ENABLE(5)
#define MPU_REG_SUBREG6_ENABLE              MPU_REG_SUBREG_ENABLE(6)
#define MPU_REG_SUBREG7_ENABLE              MPU_REG_SUBREG_ENABLE(7)
#define MPU_REG_SUBREG_DISABLE(n)           (1U << n)
#define MPU_REG_SUBREG0_DISABLE             MPU_REG_SUBREG_DISABLE(0)
#define MPU_REG_SUBREG1_DISABLE             MPU_REG_SUBREG_DISABLE(1)
#define MPU_REG_SUBREG2_DISABLE             MPU_REG_SUBREG_DISABLE(2)
#define MPU_REG_SUBREG3_DISABLE             MPU_REG_SUBREG_DISABLE(3)
#define MPU_REG_SUBREG4_DISABLE             MPU_REG_SUBREG_DISABLE(4)
#define MPU_REG_SUBREG5_DISABLE             MPU_REG_SUBREG_DISABLE(5)
#define MPU_REG_SUBREG6_DISABLE             MPU_REG_SUBREG_DISABLE(6)
#define MPU_REG_SUBREG7_DISABLE             MPU_REG_SUBREG_DISABLE(7)
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Enables MPU.
 *
 * @api
 */
void mpu_enable(const mpu_control_t ctrl);

/**
 * @brief   Configures an MPU region.
 *
 * @param[in] mrcp           pointer to region configuration
 *
 * @api
 */
void mpu_set_region(const mpu_region_config_t *mrcp);

/**
 * @brief   Disables MPU.
 *
 * @api
 */
void mpu_disable(void);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _MPU_H_ */

/** @} */
