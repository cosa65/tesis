/**********************************************************************/
/* File generated by src/simix/simcalls.py from src/simix/simcalls.in */
/*                                                                    */
/*                    DO NOT EVER CHANGE THIS FILE                    */
/*                                                                    */
/* change simcalls specification in src/simix/simcalls.in             */
/* Copyright (c) 2014-2019. The SimGrid Team. All rights reserved.    */
/**********************************************************************/

/*
 * Note that the name comes from http://en.wikipedia.org/wiki/Popping
 * Indeed, the control flow is doing a strange dance in there.
 *
 * That's not about http://en.wikipedia.org/wiki/Poop, despite the odor :)
 */

#include "smx_private.hpp"
#include <xbt/base.h>
#if SIMGRID_HAVE_MC
#include "src/mc/mc_forward.hpp"
#endif
#include "src/kernel/activity/ConditionVariableImpl.hpp"

XBT_LOG_EXTERNAL_DEFAULT_CATEGORY(simix_popping);

/** @brief Simcalls' names (generated from src/simix/simcalls.in) */
const char* simcall_names[] = {
    "SIMCALL_NONE",
    "SIMCALL_EXECUTION_WAIT",
    "SIMCALL_EXECUTION_WAITANY_FOR",
    "SIMCALL_EXECUTION_TEST",
    "SIMCALL_COMM_SEND",
    "SIMCALL_COMM_ISEND",
    "SIMCALL_COMM_RECV",
    "SIMCALL_COMM_IRECV",
    "SIMCALL_COMM_WAITANY",
    "SIMCALL_COMM_WAIT",
    "SIMCALL_COMM_TEST",
    "SIMCALL_COMM_TESTANY",
    "SIMCALL_MUTEX_LOCK",
    "SIMCALL_MUTEX_TRYLOCK",
    "SIMCALL_MUTEX_UNLOCK",
    "SIMCALL_COND_WAIT",
    "SIMCALL_COND_WAIT_TIMEOUT",
    "SIMCALL_SEM_ACQUIRE",
    "SIMCALL_SEM_ACQUIRE_TIMEOUT",
    "SIMCALL_IO_WAIT",
    "SIMCALL_MC_RANDOM",
    "SIMCALL_RUN_KERNEL",
    "SIMCALL_RUN_BLOCKING",
};

/** @private
 * @brief (in kernel mode) unpack the simcall and activate the handler
 *
 * This function is generated from src/simix/simcalls.in
 */
void simgrid::kernel::actor::ActorImpl::simcall_handle(int value) {
  XBT_DEBUG("Handling simcall %p: %s", &simcall, SIMIX_simcall_name(simcall.call_));
  SIMCALL_SET_MC_VALUE(simcall, value);
  if (context_->iwannadie)
    return;
  switch (simcall.call_) {
    case SIMCALL_EXECUTION_WAIT:
      simcall_HANDLER_execution_wait(&simcall, simgrid::simix::unmarshal<simgrid::kernel::activity::ExecImpl*>(simcall.args_[0]));
      break;

    case SIMCALL_EXECUTION_WAITANY_FOR:
      simcall_HANDLER_execution_waitany_for(&simcall, simgrid::simix::unmarshal<simgrid::kernel::activity::ExecImpl**>(simcall.args_[0]), simgrid::simix::unmarshal<size_t>(simcall.args_[1]), simgrid::simix::unmarshal<double>(simcall.args_[2]));
      break;

    case SIMCALL_EXECUTION_TEST:
      simcall_HANDLER_execution_test(&simcall, simgrid::simix::unmarshal<simgrid::kernel::activity::ExecImpl*>(simcall.args_[0]));
      break;

    case SIMCALL_COMM_SEND:
      simcall_HANDLER_comm_send(&simcall, simgrid::simix::unmarshal<smx_actor_t>(simcall.args_[0]), simgrid::simix::unmarshal<smx_mailbox_t>(simcall.args_[1]), simgrid::simix::unmarshal<double>(simcall.args_[2]), simgrid::simix::unmarshal<double>(simcall.args_[3]), simgrid::simix::unmarshal<unsigned char*>(simcall.args_[4]), simgrid::simix::unmarshal<size_t>(simcall.args_[5]), simgrid::simix::unmarshal<simix_match_func_t>(simcall.args_[6]), simgrid::simix::unmarshal<simix_copy_data_func_t>(simcall.args_[7]), simgrid::simix::unmarshal<void*>(simcall.args_[8]), simgrid::simix::unmarshal<double>(simcall.args_[9]));
      break;

    case SIMCALL_COMM_ISEND:
      simgrid::simix::marshal<boost::intrusive_ptr<simgrid::kernel::activity::ActivityImpl>>(simcall.result_, simcall_HANDLER_comm_isend(&simcall, simgrid::simix::unmarshal<smx_actor_t>(simcall.args_[0]), simgrid::simix::unmarshal<smx_mailbox_t>(simcall.args_[1]), simgrid::simix::unmarshal<double>(simcall.args_[2]), simgrid::simix::unmarshal<double>(simcall.args_[3]), simgrid::simix::unmarshal<unsigned char*>(simcall.args_[4]), simgrid::simix::unmarshal<size_t>(simcall.args_[5]), simgrid::simix::unmarshal<simix_match_func_t>(simcall.args_[6]), simgrid::simix::unmarshal<simix_clean_func_t>(simcall.args_[7]), simgrid::simix::unmarshal<simix_copy_data_func_t>(simcall.args_[8]), simgrid::simix::unmarshal<void*>(simcall.args_[9]), simgrid::simix::unmarshal<bool>(simcall.args_[10])));
      simcall_answer();
      break;

    case SIMCALL_COMM_RECV:
      simcall_HANDLER_comm_recv(&simcall, simgrid::simix::unmarshal<smx_actor_t>(simcall.args_[0]), simgrid::simix::unmarshal<smx_mailbox_t>(simcall.args_[1]), simgrid::simix::unmarshal<unsigned char*>(simcall.args_[2]), simgrid::simix::unmarshal<size_t*>(simcall.args_[3]), simgrid::simix::unmarshal<simix_match_func_t>(simcall.args_[4]), simgrid::simix::unmarshal<simix_copy_data_func_t>(simcall.args_[5]), simgrid::simix::unmarshal<void*>(simcall.args_[6]), simgrid::simix::unmarshal<double>(simcall.args_[7]), simgrid::simix::unmarshal<double>(simcall.args_[8]));
      break;

    case SIMCALL_COMM_IRECV:
      simgrid::simix::marshal<boost::intrusive_ptr<simgrid::kernel::activity::ActivityImpl>>(simcall.result_, simcall_HANDLER_comm_irecv(&simcall, simgrid::simix::unmarshal<smx_actor_t>(simcall.args_[0]), simgrid::simix::unmarshal<smx_mailbox_t>(simcall.args_[1]), simgrid::simix::unmarshal<unsigned char*>(simcall.args_[2]), simgrid::simix::unmarshal<size_t*>(simcall.args_[3]), simgrid::simix::unmarshal<simix_match_func_t>(simcall.args_[4]), simgrid::simix::unmarshal<simix_copy_data_func_t>(simcall.args_[5]), simgrid::simix::unmarshal<void*>(simcall.args_[6]), simgrid::simix::unmarshal<double>(simcall.args_[7])));
      simcall_answer();
      break;

    case SIMCALL_COMM_WAITANY:
      simcall_HANDLER_comm_waitany(&simcall, simgrid::simix::unmarshal<simgrid::kernel::activity::CommImpl**>(simcall.args_[0]), simgrid::simix::unmarshal<size_t>(simcall.args_[1]), simgrid::simix::unmarshal<double>(simcall.args_[2]));
      break;

    case SIMCALL_COMM_WAIT:
      simcall_HANDLER_comm_wait(&simcall, simgrid::simix::unmarshal<simgrid::kernel::activity::CommImpl*>(simcall.args_[0]), simgrid::simix::unmarshal<double>(simcall.args_[1]));
      break;

    case SIMCALL_COMM_TEST:
      simcall_HANDLER_comm_test(&simcall, simgrid::simix::unmarshal<simgrid::kernel::activity::CommImpl*>(simcall.args_[0]));
      break;

    case SIMCALL_COMM_TESTANY:
      simcall_HANDLER_comm_testany(&simcall, simgrid::simix::unmarshal<simgrid::kernel::activity::CommImpl**>(simcall.args_[0]), simgrid::simix::unmarshal<size_t>(simcall.args_[1]));
      break;

    case SIMCALL_MUTEX_LOCK:
      simcall_HANDLER_mutex_lock(&simcall, simgrid::simix::unmarshal<smx_mutex_t>(simcall.args_[0]));
      break;

    case SIMCALL_MUTEX_TRYLOCK:
      simgrid::simix::marshal<int>(simcall.result_, simcall_HANDLER_mutex_trylock(&simcall, simgrid::simix::unmarshal<smx_mutex_t>(simcall.args_[0])));
      simcall_answer();
      break;

    case SIMCALL_MUTEX_UNLOCK:
      simcall_HANDLER_mutex_unlock(&simcall, simgrid::simix::unmarshal<smx_mutex_t>(simcall.args_[0]));
      simcall_answer();
      break;

    case SIMCALL_COND_WAIT:
      simcall_HANDLER_cond_wait(&simcall, simgrid::simix::unmarshal<smx_cond_t>(simcall.args_[0]), simgrid::simix::unmarshal<smx_mutex_t>(simcall.args_[1]));
      break;

    case SIMCALL_COND_WAIT_TIMEOUT:
      simcall_HANDLER_cond_wait_timeout(&simcall, simgrid::simix::unmarshal<smx_cond_t>(simcall.args_[0]), simgrid::simix::unmarshal<smx_mutex_t>(simcall.args_[1]), simgrid::simix::unmarshal<double>(simcall.args_[2]));
      break;

    case SIMCALL_SEM_ACQUIRE:
      simcall_HANDLER_sem_acquire(&simcall, simgrid::simix::unmarshal<smx_sem_t>(simcall.args_[0]));
      break;

    case SIMCALL_SEM_ACQUIRE_TIMEOUT:
      simcall_HANDLER_sem_acquire_timeout(&simcall, simgrid::simix::unmarshal<smx_sem_t>(simcall.args_[0]), simgrid::simix::unmarshal<double>(simcall.args_[1]));
      break;

    case SIMCALL_IO_WAIT:
      simcall_HANDLER_io_wait(&simcall, simgrid::simix::unmarshal<simgrid::kernel::activity::IoImpl*>(simcall.args_[0]));
      break;

    case SIMCALL_MC_RANDOM:
      simgrid::simix::marshal<int>(simcall.result_, simcall_HANDLER_mc_random(&simcall, simgrid::simix::unmarshal<int>(simcall.args_[0]), simgrid::simix::unmarshal<int>(simcall.args_[1])));
      simcall_answer();
      break;

    case SIMCALL_RUN_KERNEL:
      SIMIX_run_kernel(simgrid::simix::unmarshal<std::function<void()> const*>(simcall.args_[0]));
      simcall_answer();
      break;

    case SIMCALL_RUN_BLOCKING:
      SIMIX_run_blocking(simgrid::simix::unmarshal<std::function<void()> const*>(simcall.args_[0]));
      break;

    case NUM_SIMCALLS:
      break;
    case SIMCALL_NONE:
      throw std::invalid_argument(simgrid::xbt::string_printf("Asked to do the noop syscall on %s@%s",
                                                              get_cname(),
                                                              sg_host_get_name(get_host())));
    default:
      THROW_IMPOSSIBLE;
  }
}
