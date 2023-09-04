#include <nanvix/syscall.h>
#include <nanvix/const.h>
#include <nanvix/pm.h>


/**
 * @brief Retrieves process information.
 *
 * @param pid Target process ID.
 * @param buf Buffer to store process information.
 *
 * @returns 0 upon success, -1 upon failure.
 */
int get_process_info(pid_t pid, struct process_info *buf)
{
    struct process_info info;

    /* Invoke the kernel syscall. */
    if (sys_get_process_info(pid, &info) != 0)
        return -1;

    /* Copy process information to user buffer. */
    if (kmemcpy(buf, &info, sizeof(struct process_info)) != 0)
        return -1;

    return 0;
}
