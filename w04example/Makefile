MPICC?=mpicc
CFLAGS= -lm
EXE=Allreduce_stddev compare_bcast deadlock_ring pingpong reduce_avg mpi_helloworld scatter_gather_avg


all: 
	$(MPICC) Allreduce_stddev.c -o Allreduce_stddev $(CFLAGS)
	$(MPICC) compare_bcast.c -o compare_bcast $(CFLAGS)
	$(MPICC) deadlock_ring.c -o deadlock_ring $(CFLAGS)
	$(MPICC) pingpong.c -o pingpong $(CFLAGS)
	$(MPICC) reduce_avg.c -o reduce_avg $(CFLAGS)
	$(MPICC) mpi_helloworld.c -o mpi_helloworld $(CFLAGS)
	$(MPICC) scatter_gather_avg.c -o scatter_gather_avg $(CFLAGS)