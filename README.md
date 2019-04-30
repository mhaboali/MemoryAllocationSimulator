# MemoryAllocationSimulator
This is a C# GUI Application that enables the user to simulate the OS Memory Allocation process based on three methos(first fir, bet fit ,and worst fit)

The project is devided into two main parts:
  1. GUI
  2. Back-end

## GUI functions:
      1. Get inputs
      2. draw memory vector
      3. de-allocata a process
      4. compact
      5. reset
      
## Back-end functions:
      1. init_memory() //initaialize the memory with the input user holes and old processes
      2. allocate_process_first_fit(process p1)
      3. allocate_process_best_fit(process p1)
      4. allocate_process_worrst_fit(process p1)
      5. allocate_process(Enum technique) //main program functions, it calls one of the previous functions based on input method
      6. de-allocate_process(process p1) //de-allocate and compact with the neoghbouring hole if there's any
      7. compact memory()
           
      
      
  
