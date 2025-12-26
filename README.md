# Optical-Tracking-Tool-Optimization-Framework
This project provides a constraint-driven automated framework for optimizing multi-tool fiducial configurations in surgical navigation systems. The C++/MATLAB implementation enables systematic generation and accuracy ranking of optical tracking tool designs based on point-based rigid registration theory.

Key Innovation: Our framework establishes a unified pose accuracy evaluation metric applicable to both optical probes and dynamic reference frames (DRFs), overcoming limitations of traditional metrics like FRE and TRE. The optimization method incorporates both intra-group uniqueness and inter-group compatibility constraints to generate high-precision tool configurations.

Core Features
Theoretical Foundation: Based on rigorous mathematical derivation of pose deviation metrics

⟨|ΔR|²⟩ = (ε²σ²/N) · ΣᵢΣⱼ₌ᵢ [1/(fᵢ² + fⱼ²)]

### Exhaustive Configuration Generation
- Algorithmic search for valid fiducial arrangements  
- Planar DRF with **N** fiducial points  
- Customizable distance constraints (`d_min`, `d_max`, `Δd_min`)  
- Step-size controlled precision  

### Compatibility Optimization
- Multi-tool collaborative working environment support  
- Geometric uniqueness enforcement  
- Angle-based distinction criteria  
- Compatibility matrix construction  

### Accuracy Ranking
- Theoretical precision prediction with **&lt;5 %** mean error  
- Orientation-deviation expectation calculation  
- Experimental validation across multiple metrics  

### Dependencies

- **Eigen 3.3.9**
  - Purpose: matrix operations and mathematical computations  
  - Installation:
  - wget https://gitlab.com/libeigen/eigen/-/archive/3.3.9/eigen-3.3.9.tar.gz
  - tar -xzf eigen-3.3.9.tar.gz
  - sudo cp -r eigen-3.3.9 /usr/local/include/eigen3
  
- **OpenCV**
  - Purpose: Image processing and camera calibration support
  - Installation:
  - git clone https://github.com/opencv/opencv.git --branch 4.5.5
  - mkdir opencv-build && cd opencv-build
  - cmake ../opencv -DBUILD_LIST=core,calib3d,imgproc
  - make -j$(nproc) && sudo make install
  
- **VTK**
  - Purpose: 3D visualization and point cloud processing
  - Installation:
  - git clone https://gitlab.kitware.com/vtk/vtk.git --branch v8.2.0
  - mkdir VTK-build && cd VTK-build
  - cmake ../vtk -DBUILD_SHARED_LIBS=ON -DVTK_GROUP_QT=OFF
  - make -j$(nproc) && sudo make install

- **ConnectNDI**
  - Purpose: Optical tracking system communication
  - Installation:
  - Download SDK from: https://ndi.tv/sdk/
  - Set environment variable: NDI_ROOT=<installation_path>
  - Link against provided libraries in your build system

#### Build Instructions
 - Prerequisites
 - CMake 3.12+
 - C++17 compatible compiler
 - Optical tracking system (e.g., NDI Polaris)
 - Compilation



### Contributing
We welcome contributions to:
 - Additional error models for complex optical environments
 - Dynamic tracking performance optimization
 - Clinical validation in real-world scenarios
### License
 - This project is available for academic and research use. Please cite our work when using this framework in your research.
### Support
 - For technical questions or research collaborations, please contact: liuchuanba@tju.edu.cn

### Reproducibility Statement
Full source code of the proposed algorithms is permanently available at this repository. The implementation follows the mathematical framework described in our publication:

```bibtex
@article{Wang2025SurgicalNavigation,
  title   = {A Constraint-Driven Automated Framework for Optimizing Multi-Tool Fiducial Configurations in Surgical Navigation},
  author  = {Wang, Yuhui and Liu, Chuanba and Wang, Yifei and Yang, Boyu and Sun, Tao},
  journal = {journal of medical imaging},
  year    = {2025},
  url     = {https://github.com/YuHuiWang1999/Optical-Tracking-Tool-Optimization-Framework}
}

