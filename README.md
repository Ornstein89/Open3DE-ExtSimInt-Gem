# Open3DE-ExtSimInt-Gem <!-- omit from toc -->

![logo](logo.png)

Open3D Engine gem providing interaction with external simulation model without ROS, via system Inter Process Communication (IPC): video output to external model and motion input from external model.

![Under development, coming soon](/doc/img/under_construction.png)

## Contents <!-- omit from toc -->

- [Installation](#installation)
- [Usage](#usage)
- [Links and resources](#links-and-resources)
- [TODO \& current progress (dev branch)](#todo--current-progress-dev-branch)

## Installation

TODO

## Usage

TODO

## Links and resources

1. Open 3D Engine (O3DE) Tutorials and Examples. - URL: https://www.docs.o3de.org/docs/learning-guide/.
2. Open 3D Engine and Atom API Reference. - URL: https://www.docs.o3de.org/docs/api/.
3. Open 3D Engine (O3DE) User Guide. Components. - URL: https://www.docs.o3de.org/docs/user-guide/components/.
4. Open 3D Engine (O3DE) User Guide. Gems in Open 3D Engine. - URL: https://www.docs.o3de.org/docs/user-guide/gems/.

## TODO & current progress (dev branch)

- [x] Created the gem and 2 components from templates, added them to interface, successfully built and added them to entity in a project.
- [ ] External test app to translate motion parameters by IPC.
- [ ] Code to receive motion parameters by IPC from external app and move entity (`ReceiveMotionParams` component).
- [ ] Code to translate rendered picture by IPC  (`TranslatePicture` component).
- [ ] External test app to receive and display picture.

