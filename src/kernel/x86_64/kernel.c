#include <ldrtype.h>
#include <config.h>
#include <memory.h>

__attribute__((section(".data"))) kernel_desc_t kernel_info;

void copy_kernel_desc(kernel_desc_t *p_kernel_desc) {
    kernel_desc_t *temp = (kernel_desc_t *)(KERNEL_START + KERNEL_DESC_OFF);
    memcpy(temp, p_kernel_desc, sizeof(kernel_desc_t));

    if(p_kernel_desc->kernel_magic != ZHOS_MAGIC){
        while (1);
    }
}

void kernel_main() {    
    copy_kernel_desc(&kernel_info);
    while (1);
}