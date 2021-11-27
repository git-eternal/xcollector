<p align=center>
  <span><strong><a href="https://osucollector.com">osu collector</a> free edition. created in c++.</strong></span>
  <br>
  <a target="_blank" href="https://isocpp.org" title="c++20"><img src="https://img.shields.io/badge/C++-20-blue.svg"></a>
  <a target="_blank" href="license" title="License: MIT"><img src="https://img.shields.io/badge/License-MIT-red.svg"></a>
  <a target="_blank" href="https://github.com/EternalRift/scout/releases" title="releases"><img src="https://img.shields.io/badge/Release-1.0-brightgreen.svg"></a>
</p>

<hr>

## Background
<a href="https://osucollector.com">Osu collector</a> is a paid service used to download packages of organized osu beatmaps called "collections". A few days ago, I managed to find an exploit in their API (mainly due to the lack of any authentication or integrity within the API infrastructure itself) that allowed me to download any collection I wanted without paying. As a result, I decided to write a proof of concept (PoC) and release it to the public. 
Although XCollector renders this service free, I still urge you to go and support the original creators as they've put lots of time and effort into their project. XCollector merely serves as an educational tool to demonstrate how a premium service can be exploited and will likely be patched by them soon. 

## How to use
Simply open the file, type the ID of the collection you would like to download and what path it should be downloaded to. For example, if I wanted to download https://osucollector.com/collections/1910, I would put "1910" as the collection ID.
## Preview
![preview](https://media.discordapp.net/attachments/900206522297098250/914028413382164480/unknown.png)

## Compiling and contributing
#### Prerequisites
* cpr (curl-for-people)
* nlohmann-json

#### Using vcpkg
<a target="_blank" href="https://github.com/microsoft/vcpkg#quick-start-windows" title="install-vcpkg">How to install vcpkg</a>
```console
vcpkg install cpr:x86-windows-static
vcpkg install nlohmann-json:x86-windows-static
```

#### Build
```console
# clone the repo
$ git clone https://github.com/EternalRift/xcollector.git
```

* Open xcollector.sln with Visual Studio 2019 and compile with x86 Release

<hr>
