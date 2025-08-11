# AI-kernel-project
Developing a Linux kernel-level AI module designed to monitor system metrics and enable deep integration across applications for enhanced automation and task coordination. The goal is to create an intelligent system with privileged access to optimize workflows at the OS level.

## Current Progress

- Successfully built and loaded a basic Linux kernel module that exposes system metrics via the `/proc` filesystem.  
- Developed a userspace AI daemon in Python that reads these metrics and logs CPU and memory usage periodically.  
- Established smooth communication between kernel and userspace components.  
- Kernel module currently prints simple telemetry data; working towards more advanced AI-driven functionality.  
- Actively exploring Linux kernel internals and module development to deepen understanding and enhance the project.
