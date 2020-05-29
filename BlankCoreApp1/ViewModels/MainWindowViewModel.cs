using Prism.Commands;
using Prism.Mvvm;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Windows;
using zeroxzeroh.libusbTransport;

namespace BlankCoreApp1.ViewModels
{
    public class MainWindowViewModel : BindableBase
    {
        private string _title = "Prism Application";
        public string Title
        {
            get { return _title; }
            set { SetProperty(ref _title, value); }
        }
        private bool _IsConnected = false;
        public bool IsConnected
        {
            get { return _IsConnected; }
            set { SetProperty(ref _IsConnected, value); }
        }
        private string _ConnectedText = "Disconnected";
        public string ConnectedText
        {
            get { return _ConnectedText; }
            set { SetProperty(ref _ConnectedText, value); }
        }
        public UsbDevice SelectedDevice { get; set; }
        public bool IsDeviceSelected { get { return SelectedDevice == null; } }

        public UsbTransport Usb = new UsbTransport();
        public DelegateCommand ConnectCommand { get; private set; }
        public DelegateCommand RCommand { get; private set; }
        public DelegateCommand GCommand { get; private set; }
        public DelegateCommand YCommand { get; private set; }
        public ObservableCollection<UsbDevice> UsbDevices
        {
            get
            {
                return Usb.Devices;
            }
        }
        public MainWindowViewModel()
        {
            ConnectCommand = new DelegateCommand(conn);
            RCommand = new DelegateCommand(() => SelectedDevice.TxUsb(Encoding.ASCII.GetBytes("r")));
            GCommand = new DelegateCommand(() => SelectedDevice.TxQueue.Enqueue(Encoding.ASCII.GetBytes("g")));
            YCommand = new DelegateCommand(() => SelectedDevice.TxQueue.Enqueue(Encoding.ASCII.GetBytes("y")));
        }
        private void conn()
        {
            if (SelectedDevice != null)
            {
                IsConnected = SelectedDevice.OpenDevice();
                ConnectedText = IsConnected == true ? "Connected" : "Disconnected";
            }
            else
            {
                MessageBox.Show("Please choose device first");
            }
        }
    }
}
