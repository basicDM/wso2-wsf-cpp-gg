# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.
# The ASF licenses this file to You under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance with
# the License.  You may obtain a copy of the License at
# 
#   http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
noinst_PROGRAMS = round1 
round1_SOURCES = round1_client.c

round1_LDADD   =    $(LDFLAGS) \
                    ../../../../util/src/libaxutil.la \
                    ../../../../axiom/src/om/libaxis2_axiom.la \
                    ../../../../axiom/src/parser/$(WRAPPER_DIR)/libaxis2_parser.la \
					$(top_builddir)/src/core/engine/libaxis2_engine.la \
					$(top_builddir)//src/core/transport/http/sender/libaxis2_http_sender.la \
					$(top_builddir)/src/core/transport/http/receiver/libaxis2_http_receiver.la \
					$(top_builddir)/src/core/transport/http/common/libaxis2_http_common.la

INCLUDES = -I$(top_builddir)/include \
            -I ../../../../util/include \
            -I ../../../../axiom/include

