/*****************************************************************************\
 *  builtin_wrapper.c - NO-OP plugin for SLURM's internal scheduler.
 *****************************************************************************
 *  Copyright (C) 2002 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Kevin Tew <tew1@llnl.gov> et. al.
 *  UCRL-CODE-226842.
 *  
 *  This file is part of SLURM, a resource management program.
 *  For details, see <http://www.llnl.gov/linux/slurm/>.
 *  
 *  SLURM is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *
 *  In addition, as a special exception, the copyright holders give permission 
 *  to link the code of portions of this program with the OpenSSL library under 
 *  certain conditions as described in each individual source file, and 
 *  distribute linked combinations including the two. You must obey the GNU 
 *  General Public License in all respects for all of the code used other than 
 *  OpenSSL. If you modify file(s) with this exception, you may extend this 
 *  exception to your version of the file(s), but you are not obligated to do 
 *  so. If you do not wish to do so, delete this exception statement from your
 *  version.  If you delete this exception statement from all source files in 
 *  the program, then also delete it here.
 *  
 *  SLURM is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with SLURM; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
\*****************************************************************************/

#include <stdio.h>
#include <slurm/slurm_errno.h>

#include "src/common/plugin.h"
#include "src/common/log.h"
#include "src/slurmctld/slurmctld.h"

const char		plugin_name[]	= "SLURM Built-in Scheduler plugin";
const char		plugin_type[]	= "sched/builtin";
const uint32_t		plugin_version	= 100;

/* A plugin-global errno. */
static int plugin_errno = SLURM_SUCCESS;

/**************************************************************************/
/*  TAG(                              init                              ) */
/**************************************************************************/
int init( void )
{
	verbose( "Built-in scheduler plugin loaded" );
	return SLURM_SUCCESS;
}

/**************************************************************************/
/*  TAG(                              fini                              ) */
/**************************************************************************/
void fini( void )
{
	/* Empty. */
}

/**************************************************************************/
/* TAG(              slurm_sched_plugin_reconfig                        ) */
/**************************************************************************/
int slurm_sched_plugin_reconfig( void )
{
	return SLURM_SUCCESS;
}

/***************************************************************************/
/*  TAG(                   slurm_sched_plugin_schedule                   ) */
/***************************************************************************/
int
slurm_sched_plugin_schedule( void )
{
	return SLURM_SUCCESS;
}


/**************************************************************************/
/* TAG(                   slurm_sched_plugin_initial_priority           ) */ 
/**************************************************************************/
u_int32_t
slurm_sched_plugin_initial_priority( u_int32_t last_prio,
				     struct job_record *job_ptr )
{
	if (last_prio >= 2)
		return (last_prio - 1);
	else
		return 1;
}

/**************************************************************************/
/* TAG(              slurm_sched_plugin_job_is_pending                  ) */
/**************************************************************************/
void slurm_sched_plugin_job_is_pending( void )
{
	/* Empty. */
}

/**************************************************************************/
/* TAG(              slurm_sched_plugin_partition_change                ) */
/**************************************************************************/
void slurm_sched_plugin_partition_change( void )
{
	/* Empty. */
}

/**************************************************************************/
/* TAG(              slurm_sched_get_errno                              ) */
/**************************************************************************/
int slurm_sched_get_errno( void )
{
	return plugin_errno;
}

/**************************************************************************/
/* TAG(              slurm_sched_strerror                               ) */
/**************************************************************************/
char *slurm_sched_strerror( int errnum )
{
	return NULL;
}

/**************************************************************************/
/* TAG(              slurm_sched_plugin_requeue                         ) */
/**************************************************************************/
void slurm_sched_plugin_requeue( struct job_record *job_ptr, char *reason )
{
	/* Empty. */
}

/**************************************************************************/
/* TAG(              slurm_sched_get_conf                               ) */
/**************************************************************************/
char *slurm_sched_get_conf( void )
{
	return NULL;
}
