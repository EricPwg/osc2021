# include "vfs.h"
# include "typedef.h"

# define FAT32FS_DEFAULT_MODE   6

struct fat32fs_internal{
  uint32_t size;
  uint32_t first_cluster;
  uint32_t *clusters;
};

//void tmpfs_get_mount_fs(struct mount* mount_point);
struct filesystem* fat32fs_get_fs();
int fat32fs_setup_mount(struct filesystem* fs, struct mount* mount);
int fat32fs_unmount(struct mount *mount);
int fat32fs_mkdir(struct vnode* dir_name, struct vnode** target, const char* component_name);
int fat32fs_create(struct vnode* dir_name, struct vnode** target, const char* component_name);
int fat32fs_read(struct file* file, void* buf, size_t len);
int fat32fs_write(struct file* file, const void* buf, size_t len);
int fat32fs_file_cat(struct vnode *vnode);
int fat32fs_dir_cat(struct vnode *vnode);
int fat32fs_get_size(struct vnode *vnode);
int fat32fs_rm(struct vnode *vnode);
int fat32fs_dir_release(struct vnode *vnode);
int fat32fs_file_release(struct vnode *vnode);
