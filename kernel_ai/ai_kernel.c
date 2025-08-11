#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("You");
MODULE_DESCRIPTION("Minimal /proc example with seq_printf");
MODULE_VERSION("0.1");

#define PROC_NAME "ai_metrics"

// This function is called when user runs: cat /proc/ai_metrics
static int ai_metrics_show(struct seq_file *m, void *v) {
    seq_printf(m, "Hello from the kernel!\n");
    seq_printf(m, "AI metric value: %d\n", 42);
    return 0;
}

// Wrapper to link show function to seq_file API
static int ai_metrics_open(struct inode *inode, struct file *file) {
    return single_open(file, ai_metrics_show, NULL);
}

// File operations for /proc
static const struct proc_ops ai_metrics_fops = {
    .proc_open    = ai_metrics_open,
    .proc_read    = seq_read,
    .proc_lseek   = seq_lseek,
    .proc_release = single_release,
};

static int __init ai_init(void) {
    proc_create(PROC_NAME, 0, NULL, &ai_metrics_fops);
    printk(KERN_INFO "/proc/%s created\n", PROC_NAME);
    return 0;
}

static void __exit ai_exit(void) {
    remove_proc_entry(PROC_NAME, NULL);
    printk(KERN_INFO "/proc/%s removed\n", PROC_NAME);
}

module_init(ai_init);
module_exit(ai_exit);
