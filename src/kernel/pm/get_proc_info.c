#include <nanvix/syscall.h>
#include <nanvix/ulib.h>
#include <nanvix/kernel/mm.h>
#include <nanvix/runtime/pm.h>

/**
 * @brief Gets information about a process.
 *
 * @param pid Target process ID.
 * @param buf Buffer to store process information.
 *
 * @returns 0 on success, negative error code on failure.
 */
int sys_get_process_info(pid_t pid, struct process_info *buf)
{
	int ret;

	/* Invalid PID. */
	if (pid < 0)
		return -EINVAL;

	/* Invalid buffer. */
	if (buf == NULL)
		return -EFAULT;

	/* Copy process information to user buffer. */
	if ((ret = do_get_process_info(pid, buf)) < 0)
		return ret;

	return 0;
}

/**
 * @brief The main function.
 */
int main(void)
{
	int ret;
	pid_t pid = /* Process ID of the target process */;

	struct process_info info;
	ret = sys_get_process_info(pid, &info);

	if (ret < 0)
	{
		printf("Error: Could not get process information (error code: %d)\n", ret);
		return ret;
	}

	/* Process information is now available in the 'info' structure. */

	/* Example usage: */
	printf("Process ID: %d\n", info.pid);
	printf("Status Code: %d\n", info.status_code);
	printf("Priority: %d\n", info.priority);
	printf("User Mode Time: %u\n", info.user_mode_time);
	printf("Kernel Mode Time: %u\n", info.kernel_mode_time);

	return 0;
}
