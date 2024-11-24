<!-- Back to Top Link-->
<a name="readme-top"></a>


<br />
<div align="center">
  <h1 align="center">DPR Kingdom</h1>
  <p align="center">
    <h3>a real life simulation of the kingdom of DPR</h3>
    <h4>Object-Oriented Based CLI Application</h4>
    <br/>
    <!-- IMAGE OR LOGO -->
    <!-- <img src="" alt="Project Logo // Team Picture // etc">
    <br/>
    <br/> -->
    <a href="https://github.com/NoHaitch/Tubes-IF2210-OOP-K-JKW/issues">Report Bug</a>
    ·
    <a href="https://github.com/NoHaitch/Tubes-IF2210-OOP-K-JKW/issues">Request Feature</a>
<br>
<br>

[![MIT License][license-shield]][license-url]

  </p>
</div>

<!-- CONTRIBUTOR -->
<div align="center" id="contributor">
  <strong>
    <h3>Made By:</h3>
    <h3>Kelompok JKW</h3>
    <h3>Nasi Cumi Hitam Madura Pak Bagas</h3>
    <table align="center">
      <tr>
        <td>NIM</td>
        <td>Nama</td>
      </tr>
      <tr>
        <td>13522037</td>
        <td>Farhan Nafis Rayhan</td>
      </tr>
      <tr>
        <td>13522071</td>
        <td>Bagas Sambega Rosyada</td>
      </tr>
      <tr>
        <td>13522091</td>
        <td>Raden Francisco Trianto Bratadiningrat</td>
      </tr>
      <tr>
        <td>13522105</td>
        <td>Fabian Radenta Bangun</td>
      </tr>
    </table>
  </strong>
  <br>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
        <li><a href="#instruction">Instruction</a></li>
        <li>
        <details>
          <summary><a href="#features">Features</a></summary>
          <ol>
            <li><a href="#1-feature-x">Features - 1</a></li>
            <li><a href="#2-feature-y">Features - 2</a></li>
            <li><a href="#3-feature-z">Features - 3</a></li>
          </ol>
        </details>
        </li>
      </ul>
    </li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#special-thanks">Special Thanks</a></li>
  </ol>
</details>

## External Links

- [OOP Terpusat](https://docs.google.com/spreadsheets/d/1hly7VjxXC-PRUI0mfJ4VQ-8vLoD-YTgQIJLWD_faFGc/edit#gid=979950684)
- [Spesifikasi](https://docs.google.com/document/d/1gE2ovBWM_tM1vGqDE-SwkdymLVizFfn40q2ru6dKhwA/edit)
- [Q & A](https://docs.google.com/spreadsheets/d/14NXvZLRUP9cBqQ6Pevrnx8OXSKGFGMd8wf7PCziSIqk/edit#gid=0)
- [Teams](https://docs.google.com/spreadsheets/d/185aduUJIXUticrgKBo6GVCaUpqxhtxCuDwZQzJUpmkk/edit#gid=0)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ABOUT THE PROJECT -->
## About The Project

General Explanation about the project, Why you made this, What does it do exactly.  

<!-- OPTIONAL LINK OR REFERENCE -->
<!-- <p align="center">
You can explore more on this link ... 
<br>
<a href="https://example.com"> <Strong>THIS LINK</Strong>
</a>
</p> -->

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

Project dependencies  
example :  

* Make 
  ```sh
  # in Linux
  sudo apt install make
  ```
* g++
  ```sh
  # in Linux
  sudo apt install g++
  ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Installation

_How to install and use your project_

1. Clone the repo
   ```sh
   git clone https://github.com/NoHaitch/Tubes-1-IF2210-OOP-K-JKW
   ```

2. Install [dependencies](#prerequisites)

3. Run Makefile
   ```sh
   make all
   ```


<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- INSTURCTION -->
## Instruction
Instruction to run/build/etc the program  

`make all` : Build and run the program  
`make build` : Build object code to bin   
`make clean` : Remove object code   
`make run` : Run the program  


<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- FEATURES -->
## Features 

### There are 3 Player Roles:
#### 1. Mayor  
- Jumlahya tepat 1.
- Mayor dapat menagih pajak kepada para pemain.
- Mayor dapat membangun bangunan.
- Mayor dapat menambahkan akun Farmer atau Cattleman dengan jumlah uang bawaan 50 gulden dengan mengurangi uang Mayor.
#### 2. Farmer  
- Jumlahnya >= 0.
- Farmer dapat menanam tanaman dan memanen tanaman yang telah ditanam.
#### 3. Cattleman  
- Jumlahnya >= 0.
- Cattleman dapat menaruh hewan di ladang ternaknya.
- Cattleman dapat memberi makan hewan di ladang ternaknya.
- Cattleman dapat memanen hewan yang telah siap panen.

### Storage

Every player have a storage with the size n x m.   
Some player role have spesifics storage.     
Storage types: products, animals, plants.

### Taxes

Mayor can collect taxes from player and use it as his own money (corruption).

### Cattleing

There 3 types of animals: Herbivore, Carnivore, and Omnivore.   
A Cattleman can have a barn with the size n x m depending on the configuration

### Farming

There are 2 types of Plants: Material and Fruit Plants.   
Material Plant produces product used for building.  
Fruit Plant produces product used for eating for feeding animals.  

### Shop

Every player can buy or sell items to the shop. An item that is sold to the shop can be bough by other players. Player role cattleman and farmer can't sell buildings and Mayor can't buy buildings.

### Build Buildings 

Mayor can build buildings. Buildings can be sold to the shop. The amount of building affect the amoung of tax each player need to pay. Building has its type with each it's own value and recipe. 

### Eat

Every player can eat food that it has. It can be product from farming or cattleing. Every food will increase he player weight.

## Commands and Operation:
1. Next
2. Print Storage
3. Collect Tax
4. Print Farm or Barn
5. Plant
6. Cattle
7. Build Building
8. Eat
9. Feed Animal
10. Buy
11. Sell
12. Harvest
13. Load
14. Save
15. Add Player


<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- CONTRIBUTING -->
## Contributing

If you want to contribute or further develop the program, please fork this repository using the branch feature.  
Pull Request is **permited and warmly welcomed**

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## Licensing

The code in this project is licensed under Apache-2.0 license.  


<!-- SPECIAL THANKS AND/OR CREDITS -->
## Special Thanks
- [Best-README-Template](https://github.com/othneildrew/Best-README-Template) by othneildrew

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<br>
<h3 align="center"> THANK YOU! </h3>

<!-- MARKDOWN LINKS & IMAGES -->
[issues-url]: https://github.com/NoHaitch/Tubes-IF2210-OOP-K-JKW/issues
[license-shield]: https://img.shields.io/badge/License-Apache--2.0_license-yellow
[license-url]: https://github.com/NoHaitch/Tubes-IF2210-OOP-K-JKW/blob/main/LICENSE
