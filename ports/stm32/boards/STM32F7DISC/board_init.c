#include STM32_HAL_H
/**************************************************************************/
/*!
    @brief	Configure the MPU attributes as Write Through for SRAM1/2.
    @param	None.
    @retval	None.
*/
/**************************************************************************/

static void MPU_Config(void)
{
    MPU_Region_InitTypeDef MPU_InitStruct;

/* Disable the MPU */
    HAL_MPU_Disable();

/* Configure the MPU attributes as Write-Through for Internal SRAM */
    MPU_InitStruct.Enable 			= MPU_REGION_ENABLE;
    MPU_InitStruct.BaseAddress 		= 0x20010000;
    MPU_InitStruct.Size 			= MPU_REGION_SIZE_256KB;
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
    MPU_InitStruct.IsBufferable 	= MPU_ACCESS_NOT_BUFFERABLE;
    MPU_InitStruct.IsCacheable 		= MPU_ACCESS_CACHEABLE;
    MPU_InitStruct.IsShareable 		= MPU_ACCESS_NOT_SHAREABLE;
    MPU_InitStruct.Number 			= MPU_REGION_NUMBER0;
    MPU_InitStruct.TypeExtField 	= MPU_TEX_LEVEL0;
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.DisableExec 		= MPU_INSTRUCTION_ACCESS_ENABLE;
    HAL_MPU_ConfigRegion(&MPU_InitStruct);

/* Configure the MPU attributes as Write-Through for External SDRAM */
    MPU_InitStruct.Enable 			= MPU_REGION_ENABLE;
    MPU_InitStruct.BaseAddress 		= 0xC0000000;
    MPU_InitStruct.Size 			= MPU_REGION_SIZE_8MB;
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
    MPU_InitStruct.IsBufferable 	= MPU_ACCESS_NOT_BUFFERABLE;
    MPU_InitStruct.IsCacheable 		= MPU_ACCESS_CACHEABLE;
    MPU_InitStruct.IsShareable 		= MPU_ACCESS_NOT_SHAREABLE;
    MPU_InitStruct.Number 			= MPU_REGION_NUMBER1;
    MPU_InitStruct.TypeExtField 	= MPU_TEX_LEVEL0;
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.DisableExec 		= MPU_INSTRUCTION_ACCESS_ENABLE;
    HAL_MPU_ConfigRegion(&MPU_InitStruct);

/* Enable the MPU */
    HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);

}


void STM32F7DISC_board_early_init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    __HAL_RCC_GPIOK_CLK_ENABLE();

    // Turn off the backlight. LCD_BL_CTRL = PK3
    GPIO_InitStructure.Pin = GPIO_PIN_3;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOK, &GPIO_InitStructure);
    HAL_GPIO_WritePin(GPIOK, GPIO_PIN_3, GPIO_PIN_RESET);

    MPU_Config();
}
