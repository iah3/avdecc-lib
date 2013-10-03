/*
 * Licensed under the MIT License (MIT)
 *
 * Copyright (c) 2013 AudioScience Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * system_multithreaded_callback.h
 *
 * Multithreaded System implementation class
 */

#pragma once
#ifndef _SYSTEM_MULTITHREADED_CALLBACK_H_
#define _SYSTEM_MULTITHREADED_CALLBACK_H_

#include "system.h"

namespace avdecc_lib
{
        class system_multithreaded_callback : public virtual system
        {
        private:
                struct poll_thread_data
                {
                        uint8_t *frame;
                        uint16_t mem_buf_len;
                        void *notification_id;
                        uint32_t notification_flag;
                };

                struct thread_creation
                {
                        LPTHREAD_START_ROUTINE thread;
                        HANDLE handle;
                        DWORD id;
                        HANDLE kill_sem;
                };

                struct msg_poll
                {
                        struct thread_creation queue_thread;
                        system_message_queue *rx_queue;
                        system_message_queue *tx_queue;
                        HANDLE timeout_event;
                };

                enum wpcap_events
                {
                        WPCAP_TIMEOUT,
                        WPCAP_RX_PACKET,
                        WPCAP_TX_PACKET,
                        KILL_ALL,
                        NUM_OF_EVENTS
                };

                static struct msg_poll poll_rx;
                static struct msg_poll poll_tx;
                static struct thread_creation poll_thread;
                static HANDLE poll_events_array[NUM_OF_EVENTS];
                static HANDLE waiting_sem;

                static bool is_waiting;
                static void *waiting_notification_id;

        public:
                /**
                 * An empty constructor for system_multithreaded_callback
                 */
                system_multithreaded_callback();

                /**
                 * A constructor for system_multithreaded_callback used for constructing an object with network interface, notification, and logging callback functions.
                 */
                system_multithreaded_callback(net_interface *netif,
                                              controller *controller_ref,
                                              void (*notification_callback) (void *, int32_t, uint64_t, uint16_t, uint16_t, uint16_t, void *),
                                              void (*log_callback) (void *, int32_t, const char *, int32_t));

                /**
                 * Destructor for system_multithreaded_callback used for destroying objects
                 */
                virtual ~system_multithreaded_callback();

                /**
                 * Deallocate memory
                 */
                AVDECC_LIB_API void STDCALL destroy();

                /**
                 * Store the frame to be sent in a queue.
                 */
                int queue_tx_frame(void *notification_id, uint32_t notification_flag, uint8_t *frame, size_t mem_buf_len);

                /**
                 * Wait for the response packet with the corrsponding notifying id to be received.
                 */
                int wait_for_cmd_completion(void *notification_id);

        private:
                /**
                 * Start of the packet capture thread used for capturing packets.
                 */
                static DWORD WINAPI proc_wpcap_thread(LPVOID lpParam);

                /**
                 * Start of the polling thread used for polling events.
                 */
                static DWORD WINAPI proc_poll_thread(LPVOID lpParam);

                /**
                 * Create and initialize threads, events, and semaphores for wpcap thread.
                 */
                int init_wpcap_thread();

                /**
                 * Create and initialize threads, events, and semaphores for poll thread.
                 */
                int init_poll_thread();

                /**
                 * Execute poll events.
                 */
                static int poll_single();

        public:
                /**
                 * Start point of the system process, which calls the thread initialization function.
                 */
                AVDECC_LIB_API int STDCALL process_start();

                /**
                 * End point of the system process, which terminates the threads.
                 */
                AVDECC_LIB_API int STDCALL process_close();
        };
}

#endif