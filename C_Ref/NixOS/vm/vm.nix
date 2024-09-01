{ pkgs, ... }:
{
  imports = [
    <nixpkgs/nixos/modules/profiles/qemu-guest.nix>
    <nixpkgs/nixos/modules/virtualisation/qemu-vm.nix>
  ];

  # Root with empty password
  users.extraUsers.root.password = "";
  users.mutableUsers = false;

  system.stateVersion = "22.11";
}
