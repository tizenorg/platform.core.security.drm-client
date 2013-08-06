Name:       drm-client
Summary:    DRM client Package
Version:    0.0.30
Release:    0
Group:      Security/Libraries
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
Source1001: 	drm-client.manifest
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(capi-base-common)
BuildRequires:  pkgconfig(glib-2.0)
BuildRequires:  cmake

%description
DRM client library (Shared Object)


%package devel
Summary:    Development files for %{name}
Group:      Security/Development
Requires:   %{name} = %{version}-%{release}
%description devel
Development files for %{name}

%prep
%setup -q
cp %{SOURCE1001} .

%build
%cmake .

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%manifest %{name}.manifest
%defattr(-,root,root,-)
%{_libdir}/*.so.*

%files devel
%manifest %{name}.manifest
%defattr(-,root,root,-)
%{_includedir}/drm-client/*
%{_libdir}/*.so
%{_libdir}/pkgconfig/drm-client.pc

%clean
rm -rf CMakeCache.txt
rm -rf CMakeFiles
rm -rf cmake_install.cmake
rm -rf Makefile
rm -rf install_manifest.txt
rm -rf *.pc
rm -rf documentation.list

rm -rf libdrm-client.so libdrm-client.so.0 libdrm-client.so.0.0.1
