.. Copyright (c) 2017, Martin Renou, Johan Mabille, Sylvain Corlay, and
   Wolf Vollprecht

   Distributed under the terms of the BSD 3-Clause License.

   The full license is in the file LICENSE, distributed with this software.

Build and configuration
=======================

Build
-----

``xeus-python`` build supports the following options:

- ``BUILD_TESTS``: enables the ``xtest`` and ``xbenchmark`` targets (see below).
- ``DOWNLOAD_GTEST``: downloads ``gtest`` and builds it locally instead of using a binary installation.
- ``GTEST_SRC_DIR``: indicates where to find the ``gtest`` sources instead of downloading them.
- ``XEUS_PYTHONHOME_RELPATH``: indicates the relative path of the PYTHONHOME with respect to the installation prefix.

The ``BUILD_TESTS`` and ``DOWNLOAD_GTEST`` options are disabled by default. Enabling ``DOWNLOAD_GTEST`` or
setting ``GTEST_SRC_DIR`` enables ``BUILD_TESTS``. If the ``BUILD_TESTS`` option is enabled, the `xtest` target is made available, which builds and run the test suite.

By default, ``XEUS_PYTHONHOME_RELPATH`` is unset and the PYTHONHOME is set to the installation prefix, which is the expected behavior for most cases.

A situation in which we may need to specify a different value for ``XEUS_PYTHONHOME_RELPATH`` is when using a Python installation from a different prefix. This occurs for example when building the conda package for xeus-python windows, since Python is installed in the general PREFIX while xeus-python is installed in the LIBRARY_PREFIX.
