#include <stdio.h>

int main() {
    int memory_partitions[] = {300, 600, 350, 200, 750, 125};
    int num_partitions = 6;
    int processes[] = {115, 500, 358, 200, 375};
    int num_processes = 5;


    int allocated[num_partitions];
    for (int i = 0; i < num_partitions; i++) {
        allocated[i] = 0; 
    }

   
    for (int i = 0; i < num_processes; i++) {
        int process_size = processes[i];
        int partition_index = -1;
        for (int j = 0; j < num_partitions; j++) {
            if (memory_partitions[j] >= process_size && allocated[j] == 0) {
                partition_index = j;
                break;
            }
        }
        if (partition_index != -1) {
            printf("Process of size %d KB is allocated to memory partition %d (%d KB)\n",
                   process_size, partition_index, memory_partitions[partition_index]);
            allocated[partition_index] = 1;
        } else {
            printf("Process of size %d KB cannot be allocated\n", process_size);
        }
    }

    return 0;
}
