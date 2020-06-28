
# ARK Ledger App Development Environment Installation and Usage

<!--ts-->
* [The Vagrant Development Environment](#the-ledger-vagrant-environment)
  * [Requirements](#requirements)
  * [Installing Vagrant and VirtualBox](#installing-vagrant-and-virtualbox)
  * [Initializing the Ledger-Vagrant Machine](#initializing-the-ledger-vagrant-machine)
  * [Connecting to the Vagrant machine](#connecting-to-the-vagrant-machine)
  * [Vagrant Troubleshooting](#vagrant-troubleshooting)
* [Building and Flashing](#building-and-flashing)
  * [Building the Ledger ARK app](#building-the-ledger-ark-app)
  * [Flashing the Ledger ARK app](#flashing-the-ledger-ark-app)
* [Debugging](#debugging)

<!--te-->
## The Vagrant Development Environment

Although the Vagrant environment is optional, it is highly recommended for development.  
i.e. we _can_ use Python & the [ledgerblue CLI](https://github.com/LedgerHQ/blue-loader-python), but using Vagrant keeps the host system safe from unwanted modification and ensures code portability.

The projects `src/`, `example/`, and `glyphs/` folders are configured to sync with the Vagrant shell, so any changes to files in those directories will be updated to the development environment accordingly.  
At this time, the rebuild script and the Makefile do not sync. Modifying those files requires calling `vagrant halt && vagrant up --provision` from outside the shell.

---

### Requirements

* Ledger Nano S
* Vagrant
* VirtualBox

---

### Installing Vagrant and VirtualBox

#### Linux

1) **Download and run the installer for VirtualBox `6.0.14`**:  
  `https://download.virtualbox.org/virtualbox/6.0.14/VirtualBox-6.0.14-133895-Linux_amd64.run`
2) **Download and install the Oracle VM VirtualBox Extension Pack `6.0.14`**:  
  `https://download.virtualbox.org/virtualbox/6.0.14/Oracle_VM_VirtualBox_Extension_Pack-6.0.14.vbox-extpack`
3) **Download and run the Vagrant `2.2.6` installer**:  
  `https://releases.hashicorp.com/vagrant/2.2.6/vagrant_2.2.6_linux_amd64.zip`

>System-specific packages can be found at the following links:
>
> * `https://www.virtualbox.org/wiki/Download_Old_Builds_6_0`
> * `https://www.vagrantup.com/downloads.html`

<!-- At this time, the most recent version of virtualbox (6.1.2) is incompatible with vagrant.
The manual package installation steps outlined above are tested as working.
```shell
sudo apt install virtualbox
sudo apt install vagrant
``` -->

#### macOS

1) **Download and run the installer for VirtualBox `6.0.14`**:  
  `https://download.virtualbox.org/virtualbox/6.0.14/VirtualBox-6.0.14-133895-OSX.dmg`
2) **Download and install the Oracle VM VirtualBox Extension Pack `6.0.14`**:  
  `https://download.virtualbox.org/virtualbox/6.0.14/Oracle_VM_VirtualBox_Extension_Pack-6.0.14.vbox-extpack`
3) **Download and run the Vagrant `2.2.6` installer**:  
  `https://releases.hashicorp.com/vagrant/2.2.6/vagrant_2.2.6_x86_64.dmg`

<!-- At this time, the most recent version of virtualbox (6.1.2) is incompatible with vagrant.
The manual package installation steps outlined above are tested as working.
```shell
brew cask install virtualbox
brew cask install vagrant
``` -->

#### Windows

1) **Download and run the installer**:  
  `https://download.virtualbox.org/virtualbox/6.0.10/VirtualBox-6.0.10-132072-Win.exe`
2) **Download and install the Oracle VM VirtualBox Extension Pack**:  
  `https://download.virtualbox.org/virtualbox/6.0.10/Oracle_VM_VirtualBox_Extension_Pack-6.0.10.vbox-extpack`
3) **Download and run the Vagrant installer**:  
  `https://releases.hashicorp.com/vagrant/2.2.5/vagrant_2.2.5_x86_64.msi`

>note:
>
>Vagrant on Windows requires using **PowerShell**.
>
>**VSCode** also uses Windows Powershell as its default terminal;  
>it is the recommended development environment.
> - [VSCode Download Page](https://code.visualstudio.com/download)

---

### Initializing the Ledger-Vagrant Machine

```shell
vagrant up
```

_note: setup will take a few minutes to provision._

---

### Connecting to the Vagrant machine

```shell
vagrant ssh
```

---

### Vagrant Troubleshooting

**USB Port locked out of the host machine**:

* Try restarting the Vagrant Box from outside the shell.
  * `vagrant halt && vagrant up`

**Ledger not found in the Vagrant Box**:

* On Ubuntu, if the Ledger is not found in the vagrant box, ensure that the **host** user belongs to the vboxusers group.
  * `sudo usermod -aG vboxusers <username>`
    (_see [askubuntu.com/How to set up USB for VirtualBox](https://askubuntu.com/questions/25596/how-to-set-up-usb-for-virtualbox/25600#25600)_)
* Try another USB Cable. Prefer the Ledger-supplied cable.
    Not all USB cables are created equal; and though rare, compromised cables have been found in the wild.

---

## Building and Flashing

Connect the Ledger device in before flashing.

The Build and Flash commands are executed from project root:

**Vagrant Shell**: `~/apps/ledger-app-ark`

### Rebuild Script

#### NanoS

```shell
bash ./scripts/rebuild.sh
```

#### NanoX

```shell
bash ./scripts/rebuild.sh -x
```

---

## Debugging

Along the way, debugging can save a lot of headaches when developing for embedded environments like Ledger.

Specifically, Debugging on Ledger allows:

* Use of **PRINTF** and Console printing.
* Custom Certificates.
* Session Pin-bypass.

See the following for more information on setting up debugging:

* [**Ledger Documentation Hub: Debugging**](https://ledger.readthedocs.io/en/latest/userspace/debugging.html)

***Be sure to also enable Debugging in the projects Makefile**:

```make
# DEBUG = 0
DEBUG = 1
```
