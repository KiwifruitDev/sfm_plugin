# sfm_plugin

Based on the [Sample Plugin](https://wiki.alliedmods.net/Sample_Plugins_(Metamod:Source)#Sample_Plugin) for Metamod: Source.

## Building

Set the following environment variables:

- `MMSOURCE18`: Path to the [metamod-source](https://github.com/alliedmodders/metamod-source) repository.
- `HL2SDK-BLADE`: Path to the [hl2sdk](https://github.com/alliedmodders/hl2sdk) repository with the `blade` branch checked out.
  - Until pull request [#104](https://github.com/alliedmodders/hl2sdk/pull/104) is merged, check out the `blade-update-import-libs` branch instead.

Afterwards, set the configuration to `Release - Blade Symphony` and platform to `x64` within Visual Studio.

The plugin should build and without any errors, it can be loaded using this directory structure:

```text
addons/
├── metamod/
│   ├── bin/
│   │   └── win64/
│   │       ├── metamod.2.blade.dll
│   │       └── server.dll
│   └── sfm_plugin_x64.vdf
├── sfm_plugin/
│   └── bin/
│       └── win64/
│           └── sfm_plugin.dll
└── metamod_x64.vdf
```
