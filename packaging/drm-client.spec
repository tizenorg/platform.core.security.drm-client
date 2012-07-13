Name:       drm-client
Summary:    DRM client Package
Version:    0.0.8
Release:    0
Group:      TO_BE/FILLED_IN
License:    Apache
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(capi-base-common)
BuildRequires:  cmake

%description
DRM client library (Shared Object)


%package devel
Summary:    Development files for %{name}
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}
%description devel
Development files for %{name}

%prep
%setup -q

%build
cmake . -DCMAKE_INSTALL_PREFIX=%{_prefix}

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install

%files
%defattr(-,root,root,-)
%{_libdir}/*.so.*

%files devel
%defattr(-,root,root,-)
%{_includedir}/drm-client/*
%{_libdir}/*.so
%{_libdir}/pkgconfig/drm-client.pc
