//
// Alters header defines to allow compatability with Unikraft
// Created by Dylan Mayor on 30/11/2020.
//

#ifndef UNI_LIBSGX_DRIVER_SGX_UK_H

/* Header includes */
#include <uk/bitops.h>
#include <uk/list.h>
#include <sys/types.h>
/* End of header includes */
////////////////////////////////////////////////////////////////////////////////
/* linux/asm.h definitions */
#ifndef _EXPAND_EXTABLE_HANDLE
# define _EXPAND_EXTABLE_HANDLE(x) #x
#endif

#ifndef _ASM_EXTABLE
# define _ASM_EXTABLE(from, to)						\
	" .pushsection \"__ex_table\",\"a\"\n"				\
	" .balign 4\n"							\
	" .long (" #from ") - .\n"					\
	" .long (" #to ") - .\n"					\
	" .long (" _EXPAND_EXTABLE_HANDLE(ex_handler_default) ") - .\n"	\
	" .popsection\n"
#endif
/* End of linux/asm.h definitions */
////////////////////////////////////////////////////////////////////////////////
/* uk/bitops.h name defines */
#ifndef find_first_zero_bit
# define find_first_zero_bit(a, b) uk_find_first_zero_bit(a, b)
#endif

#ifndef find_first_bit
# define find_first_bit(a, b) uk_find_first_bit(a, b)
#endif

#ifndef set_bit
# define set_bit(a, b) uk_set_bit(a, b)
#endif

#ifndef clear_bit
# define clear_bit(a, b) uk_clear_bit(a, b)
#endif
/* End of uk/bitops.h name defines */
////////////////////////////////////////////////////////////////////////////////
/* Type declarations  */
#ifndef u64
# define u64 __u64
#endif

#ifndef u32
# define u32 __u32
#endif

#ifndef PAGE_SIZE
# define PAGE_SIZE __PAGE_SIZE
#endif
/* End of Type declarations*/
////////////////////////////////////////////////////////////////////////////////
/* uk/list.h name defines */
#ifndef list_for_each_entry
# define list_for_each_entry(a, b, c) uk_list_for_each_entry(a, b, c)
#endif
/*End of uk/list.h name defines*/
////////////////////////////////////////////////////////////////////////////////
/*pr_err name  defines */
#ifndef pr_err
# define pr_err(err) uk_pr_err(err)
#endif

#ifndef pr_warn
# define pr_warn(warn) uk_pr_warn(warn)
#endif
/*End of pr_err name defines */
////////////////////////////////////////////////////////////////////////////////
#define UNI_LIBSGX_DRIVER_SGX_UK_H
#endif // UNI_LIBSGX_DRIVER_SGX_UK_H
